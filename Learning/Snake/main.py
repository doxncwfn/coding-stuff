import pygame
import time
import random

pygame.init()

# Kích thước màn hình
WIDTH, HEIGHT = 600, 400

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

# Kích thước ô vuông rắn
BLOCK_SIZE = 15

# Tốc độ của rắn
SNAKE_SPEED = 10

screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake Game")

# Đồng hồ kiểm soát tốc độ
clock = pygame.time.Clock()

# Hiển thị điểm
def show_score(score):
    font = pygame.font.SysFont("comicsans", 35)
    score_text = font.render(f"Scores: {score}", True, WHITE)
    screen.blit(score_text, [10, 10])

# Trò chơi chính
def game_loop():
    # Khởi tạo vị trí rắn
    snake_pos = [100, 50]
    snake_body = [[100, 50], [90, 50], [80, 50]]

    # Vị trí ban đầu của mồi
    food_pos = [random.randrange(1, (WIDTH // BLOCK_SIZE)) * BLOCK_SIZE,
                random.randrange(1, (HEIGHT // BLOCK_SIZE)) * BLOCK_SIZE]
    food_spawn = True

    # Hướng di chuyển ban đầu
    direction = 'RIGHT'
    change_to = direction

    score = 0

    while True:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP and direction != 'DOWN':
                    change_to = 'UP'
                elif event.key == pygame.K_DOWN and direction != 'UP':
                    change_to = 'DOWN'
                elif event.key == pygame.K_LEFT and direction != 'RIGHT':
                    change_to = 'LEFT'
                elif event.key == pygame.K_RIGHT and direction != 'LEFT':
                    change_to = 'RIGHT'
                elif event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    quit()

        # Cập nhật hướng di chuyển
        direction = change_to

        if direction == 'UP':
            snake_pos[1] -= BLOCK_SIZE
        if direction == 'DOWN':
            snake_pos[1] += BLOCK_SIZE
        if direction == 'LEFT':
            snake_pos[0] -= BLOCK_SIZE
        if direction == 'RIGHT':
            snake_pos[0] += BLOCK_SIZE

        # Tăng chiều dài rắn nếu ăn mồi
        snake_body.insert(0, list(snake_pos))
        if snake_pos[0] == food_pos[0] and snake_pos[1] == food_pos[1]:
            score += 1
            food_spawn = False
        else:
            snake_body.pop()

        # Tạo mồi mới
        if not food_spawn:
            food_pos = [random.randrange(1, (WIDTH // BLOCK_SIZE)) * BLOCK_SIZE,
                        random.randrange(1, (HEIGHT // BLOCK_SIZE)) * BLOCK_SIZE]
        food_spawn = True

        # Xóa màn hình
        screen.fill(BLACK)

        # Vẽ rắn và mồi
        for block in snake_body:
            pygame.draw.rect(screen, GREEN, pygame.Rect(block[0], block[1], BLOCK_SIZE, BLOCK_SIZE))

        pygame.draw.rect(screen, RED, pygame.Rect(food_pos[0], food_pos[1], BLOCK_SIZE, BLOCK_SIZE))

        # Kiểm tra va chạm
        if (snake_pos[0] < 0 or snake_pos[0] >= WIDTH or
            snake_pos[1] < 0 or snake_pos[1] >= HEIGHT):
            game_over(score)

        # Kiểm tra rắn cắn chính mình
        for block in snake_body[1:]:
            if snake_pos[0] == block[0] and snake_pos[1] == block[1]:
                game_over(score)

        # Hiển thị điểm
        show_score(score)

        # Cập nhật màn hình
        pygame.display.update()

        # Điều chỉnh tốc độ rắn
        clock.tick(SNAKE_SPEED)

# Kết thúc trò chơi
def game_over(score):
    font = pygame.font.SysFont("comicsans", 50)
    game_over_text = font.render("Game Over!", True, RED)
    score_text = font.render(f"You Scored: {score}", True, WHITE)

    screen.fill(BLACK)
    screen.blit(game_over_text, [WIDTH // 4, HEIGHT // 3])
    screen.blit(score_text, [WIDTH // 4, HEIGHT // 2])
    pygame.display.flip()

    time.sleep(3)
    pygame.quit()
    quit()

# Chạy trò chơi
if __name__ == "__main__":
    game_loop()