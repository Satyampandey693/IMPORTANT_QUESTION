class DiningPhilosophers {
public:
 vector<sem_t> pick;
 mutex m;
    DiningPhilosophers() {
        pick.resize(5);
         for (int i = 0; i < 5; ++i) {
        sem_init(&pick[i], 0, 1);  // binary semaphore (initial value = 1)
    }
    }

    void wantsToEat(int p,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                        {
                            lock_guard<mutex> lc(m);
                             sem_wait(&pick[(p+1)%5]);
                            sem_wait(&pick[p]);
                            

                        }
                        pickLeftFork(); 
                        pickRightFork();
                        eat();
                        putLeftFork();
                        sem_post(&pick[(p+1)%5]);
                         
                        putRightFork();
                         sem_post(&pick[p]);
                           


		
    }
};