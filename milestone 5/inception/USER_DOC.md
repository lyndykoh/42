# User Documentation (Evaluation Guide)

Follow these instructions to deploy and evaluate the Inception infrastructure.

## 1. Prerequisites

Before building the project, you must map the local domain to the loopback address.
Edit the host machine's `/etc/hosts` file:

```bash
sudo nano /etc/hosts
```

Add the following line:

```text
127.0.0.1    lkoh.42.fr
```

## 2. Deployment

Navigate to the root of the repository and run the Makefile:

```bash
make
```

This command will:
1. Create the persistent data directories at `/home/lkoh/data/wordpress` and `/home/lkoh/data/mariadb`.
2. Build the custom NGINX, WordPress, and MariaDB images.
3. Launch the containers in the background via Docker Compose.

## 3. Accessing the Services

**The Website:**
* Navigate to `https://lkoh.42.fr`
* The browser will present a self-signed certificate warning. Bypass it to view the WordPress site securely over TLSv1.3.

**WordPress Admin Dashboard:**
* Navigate to `https://lkoh.42.fr/wp-admin`
* Use the credentials provided during the evaluation (stored locally in the `secrets/` directory) to verify the existence of the Administrator account and the standard user account.

## 4. Teardown & Cleanup

To safely stop the containers without losing data:

```bash
make down
```

To stop containers and prune images/networks:

```bash
make clean
```

To perform a factory reset (Warning: This deletes the local database and website files from the host machine):

```bash
make fclean
```