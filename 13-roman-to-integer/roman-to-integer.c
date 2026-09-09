int romanToInt(char* s) {
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        int current;
        int next;

        // Value of current symbol
        switch (s[i]) {
            case 'I': current = 1; break;
            case 'V': current = 5; break;
            case 'X': current = 10; break;
            case 'L': current = 50; break;
            case 'C': current = 100; break;
            case 'D': current = 500; break;
            case 'M': current = 1000; break;
        }

        // Value of next symbol
        switch (s[i + 1]) {
            case 'I': next = 1; break;
            case 'V': next = 5; break;
            case 'X': next = 10; break;
            case 'L': next = 50; break;
            case 'C': next = 100; break;
            case 'D': next = 500; break;
            case 'M': next = 1000; break;
            case '\0': next = 0; break;
        }

        // Subtract if current is smaller than next
        if (current < next)
            total -= current;
        else
            total += current;
    }

    return total;
}