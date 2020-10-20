def factorial(n: int):
    return n * factorial(n - 1) if n > 1 else 1


def factorial_iter(n: int):
    result = 1
    while n:
        result *= n
        n -= 1
    return result


def slow_power(x, n):
    result = 1
    for _ in range(n):
        result *= x
    return result


def power(x, n):
    if n == 0:
        return 1
    elif n % 2:
        return x * power(x ** 2, n // 2)
    else:
        return power(x ** 2, n // 2)


def power_iter(x, n):
    odd_value = 1

    while n > 1:
        if n % 2:
            odd_value *= x
            x *= x
            n //= 2  # n = (n - 1) / 2
        else:
            x *= x
            n //= 2

    return odd_value * x


def fib(n: int) -> int:
    return fib(n - 1) + fib(n - 2) if n > 1 else n


def fib_iter(n: int) -> int:
    if n < 2:
        return n
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b


def comb(n, k):
    return 1 if n == 1 or n == k else comb(n - 1, k - 1) + comb(n - 1, k)


def hanoi(n: int) -> int:
    return hanoi(n - 1) * 2 + 1 if n > 1 else 1


k, n = 4, 3

print(factorial(n))
print(factorial_iter(n))
print(slow_power(k, n))
print(power(k, n))
print(power_iter(k, n))
print(fib(n))
print(fib_iter(n))
print(comb(k, n))
print(hanoi(n))
