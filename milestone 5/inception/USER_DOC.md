# DEV_DOC.md - Developer Documentation

This document details the technical setup, architecture, and maintenance procedures for developers working on the Inception project.

## 1. Environment Setup from Scratch

### Prerequisites
* **Operating System**: Debian Buster/Bullseye or a similar Linux distribution.
* **Tools**: `docker`, `docker-compose`, `make`, `openssl`, and `git`.
* **Hardware**: Virtual Machine with at least 2GB RAM and 5GB disk space.

### Configuration Files
The project logic is centralized in the `srcs/` directory:
* `docker-compose.yml`: Defines the service orchestration, networks, and volumes.
* `.env`: (Required) Must contain keys like `MYSQL_ROOT_PASSWORD`, `MYSQL_USER`, `MYSQL_PASSWORD`, `WP_ADMIN_USER`, and `WP_ADMIN_PASSWORD`.
* `conf/`: Contains the configuration templates for NGINX, PHP-FPM, and MariaDB.

### Secrets Management
Passwords and sensitive data are handled via a local `secrets/` directory. Developers should:
1. Create a `secrets/` directory at the root.
2. Generate text files for `db_password.txt`, `db_root_password.txt`, and `wp_admin_password.txt`.
3. These files are mapped into the containers as read-only volumes to ensure sensitive data is not stored in the image layers.

## 2. Building and Launching
The project uses a standard **Makefile** to automate the build process and environment preparation.

* **Build**: `make` or `make all` 
  * Triggers the creation of local volume directories on the host.
  * Builds images using Dockerfiles located in `srcs/requirements/`.
  * Starts services via `docker-compose up -d`.

## 3. Management Commands
Developers can use the following commands to manage the lifecycle of the stack:

* **Stop Services**: `docker compose -f srcs/docker-compose.yml stop`
* **Restart Services**: `make re` (Performs a full down/up cycle).
* **View Logs**: `docker compose -f srcs/docker-compose.yml logs -f`
* **Interactive Shell**: `docker exec -it <container_name> /bin/bash`
* **Volume Inspection**: `docker volume ls`

## 4. Data Storage and Persistence
Persistence is achieved through **Docker Volumes** mapped to the host file system to ensure data survives container restarts or removals.

* **Database Persistence**: MariaDB data is stored in the `mariadb` volume. 
  * Host Path: `/home/lkoh/data/mariadb`
* **Application Persistence**: WordPress files (themes, plugins, uploads) are stored in the `wordpress` volume.
  * Host Path: `/home/lkoh/data/wordpress`

Both volumes are defined as `driver: local` in the `docker-compose.yml` to ensure strict control over the host storage location.
