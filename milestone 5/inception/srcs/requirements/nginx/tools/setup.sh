#!/bin/bash

mkdir -p /etc/nginx/ssl

if [ ! -f /etc/nginx/ssl/inception.crt ]; then
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -out /etc/nginx/ssl/inception.crt \
        -keyout /etc/nginx/ssl/inception.key \
        -subj "/C=SG/ST=Singapore/L=Singapore/O=42/OU=42/CN=lkoh.42.fr/UID=lkoh"
fi

exec nginx -g "daemon off;"