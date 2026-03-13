# Use the penultimate stable version of Debian
FROM debian:bookworm

# Install PHP-FPM, PHP-MySQL, and necessary utilities
RUN apt-get update -y && \
    apt-get install -y php7.4-fpm php7.4-mysql curl wget default-mysql-client && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copy your custom PHP-FPM configuration
COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

# Copy the initialization script and make it executable
COPY tools/setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup.sh

# Expose port 9000 for PHP-FPM traffic
EXPOSE 9000

# Start the container using the setup script
ENTRYPOINT ["/usr/local/bin/setup.sh"]