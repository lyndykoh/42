#!/bin/bash

# Create the SSL directory
mkdir -p /etc/nginx/ssl

# Generate a self-signed certificate if it doesn't already exist
if [ ! -f /etc/nginx/ssl/inception.crt ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -out /etc/nginx/ssl/inception.crt \
        -keyout /etc/nginx/ssl/inception.key \
        -subj "/C=SG/ST=Singapore/L=Singapore/O=42/OU=42/CN=lkoh.42.fr/UID=lkoh"
fi

# Start NGINX in the foreground (daemon off)
exec nginx -g "daemon off;"