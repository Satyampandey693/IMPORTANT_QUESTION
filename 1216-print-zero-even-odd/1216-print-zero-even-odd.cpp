class ZeroEvenOdd {
private:
    int n;
    int i = 1;
    mutex m;
    condition_variable cv;
    int turn = 0; // 0 = zero, 1 = odd, 2 = even

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        for (int count = 0; count < n; ++count) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return turn == 0; });
            printNumber(0);
            // decide next turn based on whether i is odd or even
            turn = (i % 2 == 1) ? 1 : 2;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return turn == 2 || i > n; });
            if (i > n) break;
            printNumber(i);
            ++i;
            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return turn == 1 || i > n; });
            if (i > n) break;
            printNumber(i);
            ++i;
            turn = 0;
            cv.notify_all();
        }
    }
};
