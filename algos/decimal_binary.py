def decToBinary(n):
    binaryNum = [0] * n
    i = 0;
    while (n > 0):
        binaryNum[i] = n % 2
        n = int(n // 2)
        i =i+1
    num=""
    for j in range(i - 1, -1, -1):
        num=num+str(binaryNum[j])
    return num

if __name__ == "__main__":
    for i in range(4):
        n=int(input())
        print(decToBinary(n))