#!/bin/bash

# Wait briefly to ensure MariaDB is fully booted before WordPress tries to connect
sleep 10

# Create and configure the web root directory
mkdir -p /var/www/html
cd /var/www/html

# Download and install WP-CLI
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

# Download WordPress core files
wp core download --allow-root

# Create the wp-config.php file using environment variables
if [ ! -f wp-config.php ]; then
    wp config create \
        --dbname=$SQL_DATABASE \
        --dbuser=$SQL_USER \
        --dbpass=$SQL_PASSWORD \
        --dbhost=mariadb \
        --allow-root

    # Install WordPress and create the admin user
    wp core install \
        --url=$WP_URL \
        --title=$WP_TITLE \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL \
        --allow-root

    # Create the secondary regular user
    wp user create \
        $WP_USER \
        $WP_USER_EMAIL \
        --role=author \
        --user_pass=$WP_USER_PASSWORD \
        --allow-root
fi

# Set proper ownership for the web files
chown -R www-data:www-data /var/www/html

# Start PHP-FPM in the foreground
exec /usr/sbin/php-fpm7.4 -F