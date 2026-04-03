# Inception

A System Administration project that involves building a complete web infrastructure using Docker. This project provisions a secure NGINX web server, a WordPress application, and a MariaDB database, all running in separate, isolated containers.

## 🏗️ Virtual Machines vs. Docker

To understand the architecture of this project, it is crucial to understand the difference between Virtual Machines (VMs) and Docker containers.

**Virtual Machines (VMs)**
A VM is a heavy, complete virtualization of a physical computer. It uses a Hypervisor to allocate physical hardware (RAM, CPU) to run a full, independent Guest Operating System (like Debian or Ubuntu) on top of the Host Operating System. Because every VM runs its own complete OS kernel, they are resource-intensive, slow to boot, and take up gigabytes of disk space.

**Docker Containers**
Docker, on the other hand, is a lightweight containerization technology. Instead of virtualizing the hardware to run a whole new Operating System, Docker virtualizes the *User Space*. All containers share the single Linux Kernel of the host machine. 
* **Efficiency:** Because containers don't boot an OS kernel, they start in milliseconds.
* **Isolation:** They use Linux Namespaces and Cgroups to ensure processes, networks, and file systems are isolated from each other.
* **Portability:** A container packages the application and its specific dependencies (like PHP 8.2 or NGINX) into a standardized unit that runs identically on any Docker-enabled host.

In this project, the host Debian VM provides the underlying Linux kernel, while Docker isolates NGINX, WordPress, and MariaDB into their own pristine environments.

## 📁 Repository Structure
* `Makefile`: The master build script to start, stop, and clean the infrastructure.
* `srcs/`: Contains the `docker-compose.yml`, `.env` (git-ignored), and the build contexts.
* `secrets/`: A git-ignored local directory storing raw password text files.
* `USER_DOC.md`: Instructions for evaluators on how to setup and test the project.
* `DEV_DOC.md`: Technical documentation detailing the system architecture and design choices.