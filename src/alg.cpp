// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int len, int value) {
    int left = 0, right = len, count = 0;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            int c = 0;
            while (arr[mid + c] == value) {
                c++;
                count++;
            }
            c = 1;
            while (arr[mid - c] == value) {
                c++;
                count++;
            }
        return count;
        } else if (arr[mid] < value) {
            left = mid;
        } else {right = mid;}
    }
    return count;
}

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0, left = 0, right = len -1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            int i = left + 1;
            while (i <= right && arr[i] == arr[left]) {
                count++;
                i++;
            }
            int j = right - 1;
            while (j >= left && arr[j] == arr[right]) {
                count++;
                j--;
            }
            left = i;
            right = j;
        } else if (sum < value) {left++;}
        else
        {right--;}
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int current = value - arr[i];
        count += cbinsearch(arr + i, len, current);
    }
     return count;
}
