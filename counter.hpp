#ifndef _COUNTER_
    #define _COUNTER_

    #include <string>
    #include <map>
    
        class Counter
        {
            private:
                std::string filename;
                int words{0}, spaces{0}, lines{0}, total_chars{0};

                std::map<char, int> char_count;

                void sort(std::string l);

            public:
                Counter(std::string filename);
                void start();
                void digest();

        };
#endif