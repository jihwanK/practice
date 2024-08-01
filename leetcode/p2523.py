def closestPrimes(left, right):
    def is_prime(num):
        if num == 1 or num**(0.5)**2 == num:
            return False

        for i in range(2, int(num**(0.5))+1):
            if num%i == 0:
                return False
        return True

    diff = 987654321
    primes, ans = [], []
    num1, num2 = -1, -1
    for num in range(left, right+1):
        if is_prime(num) and num1 == -1 and num2 == -1:
            num1 = num
            continue
        elif is_prime(num) and num1 != -1 and num2 == -1:
            num2 = num
        elif is_prime(num) and num1 != -1 and num2 != -1:
            num1 = num2
            num2 = num
        else:
            continue
        
        if num2 - num1 == 1:
            return [num1, num2]
        elif num2 - num1 < diff:
            diff = num2 - num1
            ans = [num1, num2]

    if num1 == -1 or num2 == -1:
        return [-1, -1]                

    return ans


if __name__ == "__main__":
    print(closestPrimes(255322, 929209))

