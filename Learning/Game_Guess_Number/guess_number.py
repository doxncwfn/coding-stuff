import random
import json
import os

HIGH_SCORE_FILE = "Game_Guess_Number/high_scores.json"

# Hàm tải điểm cao
def load_high_scores():
    if os.path.exists(HIGH_SCORE_FILE):
        with open(HIGH_SCORE_FILE, "r") as file:
            return json.load(file)
    return {}

# Hàm lưu điểm cao
def save_high_scores(high_scores):
    with open(HIGH_SCORE_FILE, "w") as file:
        json.dump(high_scores, file)

def guess_the_number():
    print("🎉 Chào mừng bạn đến với trò chơi Đoán Số! 🎉")
    
    high_scores = load_high_scores()
    
    name = input("Nhập tên của bạn: ")
    if name not in high_scores:
        high_scores[name] = 0
    
    level = 1
    score = 0
    
    while True:
        print(f"\n🔢 Cấp độ: {level}")
        upper_limit = level * 10
        secret_number = random.randint(1, upper_limit)
        
        print(f"Đoán một số trong khoảng từ 1 đến {upper_limit}.")
        attempts = 0
        
        while True:
            try:
                guess = int(input("Nhập dự đoán của bạn: "))
                attempts += 1
                if guess < secret_number:
                    print("📉 Số bí mật lớn hơn.")
                elif guess > secret_number:
                    print("📈 Số bí mật nhỏ hơn.")
                else:
                    print(f"🎉 Chúc mừng! Bạn đã đoán đúng sau {attempts} lần.")
                    score += max(10 - attempts, 1) * level
                    level += 1
                    break
            except ValueError:
                print("⛔ Vui lòng nhập một số hợp lệ.")
        
        print(f"Điểm hiện tại: {score}")
        
        if score > high_scores[name]:
            high_scores[name] = score
            print(f"🏆 Bạn đã lập kỷ lục mới với {score} điểm!")
        
        play_again = input("Bạn có muốn chơi tiếp không? (y/n): ").lower()
        if play_again != "y":
            print("\nCảm ơn bạn đã chơi! 🎮")
            print(f"Điểm cuối cùng của bạn: {score}")
            print(f"Điểm cao nhất của bạn: {high_scores[name]}")
            break
    
    save_high_scores(high_scores)

if __name__ == "__main__":
    guess_the_number()