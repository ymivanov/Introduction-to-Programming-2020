/**
 * @file   task_09.cpp
 * @author Victor Nolev
 * @date   25.11.2020
 * @brief  Two solutions for Task 9 from Practice 6.
 */

#include <iostream>

const int MAX_SIZE = 1024;

void readElements(int array[], unsigned size);

int sumElementsWithPrevailingRaisedBits(int numbers[], unsigned size);

bool hasMoreRaisedBitsThanZeros(int integer);

bool hasMoreRaisedBitsThanZerosFromMSBPosition(int integer);

int main() {
    // Task 9
    /* Напишете функция, която връща сумата на всички елементи на масива,
     * които имат повече вдигнати битове(1ци) отколкото свалени (0ли).
     * */

    /*  1. Интерпретация на условието:
     *  Разглеждаме абсолютно всички 32 бита на числото
     *  и според тях броим единиците и нулите от битовете на числото */

    /*  2. Интерпретация на условието:
     *  Намираме позицията най-старшия бит
     *  и от неговата позиция до позиция 0
     *  броим нулите и единиците от битовете на числото */

    unsigned size;
    std::cin >> size;

    int numbers[MAX_SIZE];
    readElements(numbers, size);
    int sumElements = sumElementsWithPrevailingRaisedBits(numbers, size);
    std::cout << sumElements << '\n';

    return 0;
}

void readElements(int array[], unsigned size) {
    for (int elementPosition = 0; elementPosition < size; ++elementPosition) {
        std::cin >> array[elementPosition];
    }
}

int sumElementsWithPrevailingRaisedBits(int numbers[], unsigned size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        // 1. Интерпретация на условието
        if (hasMoreRaisedBitsThanZeros(numbers[i])) {
            sum += numbers[i];
        }

        // 2. Интерпретация на условието
        /*if (hasMoreRaisedBitsThanZerosFromMSBPosition(numbers[i])) {
            sum += numbers[i];
        }*/
    }
    return sum;
}

bool hasMoreRaisedBitsThanZeros(int integer) {
    unsigned onesCounter = 0;
    unsigned zerosCounter = 0;

    for (int bitPosition = 31; bitPosition >= 0; --bitPosition) {
        int mask = 1 << bitPosition;
        bool isRaisedBit = (integer & mask) != 0;
        if (isRaisedBit) {
            // Current bit is 1
            ++onesCounter;
        } else {
            // Current bit is 0
            ++zerosCounter;
        }
    }
    return onesCounter > zerosCounter;
}

bool hasMoreRaisedBitsThanZerosFromMSBPosition(int integer) {
    unsigned onesCounter = 0;
    unsigned zerosCounter = 0;
    int msbPosition = -1;

    // Find position of the most significant bit
    for (int bitPosition = 31; bitPosition >= 0; --bitPosition) {
        int mask = 1 << bitPosition;
        bool isRaisedBit = (integer & mask) != 0;

        if (isRaisedBit && msbPosition == -1) {
            msbPosition = bitPosition;
            break;
        }
    }

    // Count 1's and 0's from most significant bit position
    for (int bitPosition = msbPosition; bitPosition >= 0; --bitPosition) {
        int mask = 1 << bitPosition;
        bool isRaisedBit = (integer & mask) != 0;
        if (isRaisedBit) {
            // Current bit is 1
            ++onesCounter;
        } else {
            // Current bit is 0
            ++zerosCounter;
        }
    }
    return onesCounter > zerosCounter;
}
