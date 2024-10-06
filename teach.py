def whileHanShu(num):
    if num == 1:
        return 1
    if num != 1:
        return num + whileHanShu(num -1)

print(whileHanShu(5))