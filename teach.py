def whileHanShu(num):
    if num == 1:
        return 1
    if num != 1:
        return num + whileHanShu(num -1)

print(whileHanShu(5))




第一次是  5  +   whileHanShu(4)

whileHanShu(4)执行是   4 +  whileHanShu(3)

whileHanShu(3)执行是   3 +  whileHanShu(2)

whileHanShu(2)执行是   2 +  whileHanShu(1)

whileHanShu(1)执行是   return 1