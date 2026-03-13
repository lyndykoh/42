# Variables
COMPOSE_FILE = ./srcs/docker-compose.yml
DATA_DIR = /home/lkoh/data

# The default target that builds and starts everything
all:
	@echo "Creating volume directories..."
	@mkdir -p $(DATA_DIR)/wordpress
	@mkdir -p $(DATA_DIR)/mariadb
	@echo "Building and starting containers..."
	@docker compose -f $(COMPOSE_FILE) up -d --build

# Stops and removes the containers and networks
down:
	@echo "Stopping containers..."
	@docker compose -f $(COMPOSE_FILE) down

# Cleans up containers, networks, images, and volumes
clean: down
	@echo "Cleaning up Docker resources..."
	@docker system prune -af
	@docker volume prune -f

# Deep clean that also removes the persistent data on your host machine
fclean: clean
	@echo "Removing local data directories..."
	@sudo rm -rf $(DATA_DIR)/wordpress
	@sudo rm -rf $(DATA_DIR)/mariadb

# Restarts the entire build from scratch
re: fclean all

.PHONY: all down clean fclean re