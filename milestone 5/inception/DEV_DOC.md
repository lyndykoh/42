# Developer Documentation (Architecture & Design)

This document outlines the strict design choices made to comply with the 42 Inception subject requirements.

## Base Images
To comply with the requirement to use the penultimate stable version of Debian or Alpine, all Dockerfiles are built from `debian:bookworm` (Debian 12). At the time of development, Trixie (Debian 13) is the current stable release, making Bookworm the correct penultimate target.

## PID 1 and Entrypoints
The subject strictly forbids the use of infinite loops (`tail -f`, `sleep infinity`, `while true`) to keep containers alive.
* **Solution:** Every container uses a custom `setup.sh` script as its `ENTRYPOINT`. 
* Once the script finishes generating configurations or creating databases, it uses the `exec` command to replace the shell process with the actual daemon (e.g., `exec nginx -g "daemon off;"` or `exec mysqld_safe`). This ensures the core service runs as PID 1 in the foreground, aligning with Docker best practices.

## Container Isolation & Networking
* **No Multi-Service Containers:** NGINX, WordPress (with PHP-FPM 8.2), and MariaDB are strictly isolated. NGINX does not exist in the WordPress container, and vice versa.
* **Internal Network:** The containers communicate via a custom Docker bridge network (`inception_network`).
* **Sole Entrypoint:** NGINX is the only container with published ports (`443:443`). MariaDB (`3306`) and WordPress (`9000`) only expose their ports to the internal Docker network.

## Security & TLS
* **Protocols:** The NGINX configuration strictly enforces `ssl_protocols TLSv1.3;`. Older, unsecure protocols are disabled.
* **Secret Management:** Passwords are not hardcoded in Dockerfiles. The `docker-compose.yml` file imports environment variables from a `.env` file, and highly sensitive credentials are managed locally to ensure no public exposure in the Git repository.

## Persistent Data (Volumes)
Docker named volumes are mapped directly to the host machine's file system:
* **WordPress files:** `/home/lkoh/data/wordpress`
* **MariaDB files:** `/home/lkoh/data/mariadb`

This ensures that the database and website configurations persist even if the containers are destroyed and rebuilt.