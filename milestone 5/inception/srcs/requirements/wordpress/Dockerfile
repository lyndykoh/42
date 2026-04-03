FROM debian:bookworm

RUN apt-get update -y && \
    apt-get install -y php8.2-fpm php8.2-mysql curl wget default-mysql-client && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

COPY conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf

COPY tools/setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup.sh

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/setup.sh"]