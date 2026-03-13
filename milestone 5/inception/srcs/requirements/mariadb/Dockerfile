# Use the penultimate stable version of Debian
FROM debian:bookworm

# Install MariaDB server
RUN apt-get update -y && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copy your custom MariaDB configuration to allow remote connections
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy the initialization script and make it executable
COPY tools/setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup.sh

# Expose port 3306 for database traffic
EXPOSE 3306

# Start the container using the setup script
ENTRYPOINT ["/usr/local/bin/setup.sh"]