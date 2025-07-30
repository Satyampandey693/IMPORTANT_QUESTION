class Foo {
public:
bool p1=false,p2=false;
condition_variable cv1,cv2;
mutex mtx;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
       
       
        
        printFirst();
        p1=true;
         cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lock(mtx);
        cv1.wait(lock, [this] { return p1; }); 
        lock.unlock();
        printSecond();
        p2=true;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        // this_thread::sleep_for(chrono::milliseconds(3));
    //    lock_guard<mutex> lock(m);
     unique_lock<mutex> lock(mtx);
        cv2.wait(lock, [this] { return p2; }); 
        lock.unlock();
    // cv2.wait(p2);
        printThird();
    }
};