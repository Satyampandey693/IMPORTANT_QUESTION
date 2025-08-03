class FooBar {
private:
    int n;
    bool p1=true,p2=false;
condition_variable cv1,cv2;
mutex mtx;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
             unique_lock<mutex> lock(mtx);
        cv1.wait(lock, [this] { return p1; }); 
        // lock.unlock();
        printFoo();
        p1=false;
        p2=true;
        cv2.notify_one();
        	
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
             unique_lock<mutex> lock(mtx);
        cv2.wait(lock, [this] { return p2; }); 
        // lock.unlock();
        printBar();
        p1=true;
        p2=false;
        cv1.notify_one();
        	
        }
    }
};