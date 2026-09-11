int totalNumbers(int* digits, int digitsSize) {
    int count = 0;

    for (int num = 100; num <= 999; num++) {
        if (num % 2 != 0)
            continue;

        int temp = num;
        int used[10] = {0};

        while (temp > 0) {
            int digit = temp % 10;
            used[digit]++;
            temp /= 10;
        }

        int possible = 1;

        for (int i = 0; i < 10; i++) {
            int available = 0;

            for (int j = 0; j < digitsSize; j++) {
                if (digits[j] == i)
                    available++;
            }

            if (used[i] > available) {
                possible = 0;
                break;
            }
        }

        if (possible)
            count++;
    }

    return count;
}