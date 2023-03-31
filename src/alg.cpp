// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return count;
    return -1;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {left++;}
        else
        {right--;}
    }
    if (count == 0) {
        return 0;
    }
    return count;
    return -1;
}

int cbinsearch(int* arr, int len, int value) {
    int left = 0, right = len - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {right = mid - 1;}
    }
    return 0;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int current = value - arr[i];
        int index = cbinsearch(arr + i, len, current);
        if (index != 0) {
            count++;
        }
    }
     return count;
}
