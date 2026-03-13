# Use the penultimate stable version of Debian (Bullseye)
FROM debian:bookworm

# Update package manager and install NGINX and OpenSSL
RUN apt-get update -y && \
    apt-get install -y nginx openssl && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copy our custom NGINX configuration file into the container
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

# Copy the initialization script
COPY tools/setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup.sh

# Expose port 443 for HTTPS traffic
EXPOSE 443

# Start the container using our script
ENTRYPOINT ["/usr/local/bin/setup.sh"]