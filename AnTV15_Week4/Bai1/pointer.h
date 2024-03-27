#ifndef POINTER_H
#define POINTER_H
#include <iostream>
using namespace std;

template <typename T>
class WeakPointer;

template <typename T>
class SharePointer{
    private:
        int* m_count;
        T* m_ptr;
        
    public:
        
        SharePointer(): m_ptr(nullptr), m_count(nullptr){}

        // constructor khi khỏi tạo obj thì tạo 1 con trở null và biến đếm tham chiếu = 1
        SharePointer(T* ptr = nullptr): m_ptr(ptr), m_count(new int(1)){}

        // copy constructor
        SharePointer(const SharePointer<T>& other){
            m_ptr = other.m_ptr;
            m_count = other.m_count;
            if (m_count) {
                (*m_count)++;
            }
        } 

        SharePointer(const WeakPointer<T>& w_ptr){
            m_ptr = w_ptr.m_ptr;
            m_count = w_ptr.m_count;
            if (m_count) {
                (*m_count)++;
            }
        } 
        // deconstructor
        ~SharePointer(){
            reset();
        }

        // trả về số lượng share_ptr chia sẽ quyền sở hữu
        unsigned int use_count() const{
            if(m_count)
                return *m_count;
            else return 0;
        }

        // trả về *ptr
        T* get() const { 
        return m_ptr; 
        }
        
        // giảm count đi 1 nếu reset obj, nếu cout về 0 thì giải phóng các đối tượng quản lý ptr và count
        void reset() {
            if (m_count) {
                (*m_count)--;
                if (*m_count == 0) {
                    delete m_ptr;
                    delete m_count;
                }
            }
            m_ptr = nullptr;
            m_count = nullptr;
        }


        void unique(){}
        void swap(const SharePointer<T> ptr2) {}

        SharePointer<T>& operator = (const SharePointer<T>& other){
            if(this != &other){
                reset();
                m_ptr = other.m_ptr;
                m_count = other.m_count;
                if (m_count) 
                    (*m_count)++;
            }
            return *this;
        }

        T& operator * () const {
            return *m_ptr;
        }

        T& operator -> () const {
            return m_ptr;
        }

        friend ostream& operator<<(ostream& os, const SharePointer<T>& sp) {
                os << sp.get();
                return os;
            }

        friend class WeakPointer<T>;
};


template <typename T>
class WeakPointer{
    private: 
        T* m_ptr;
        int *m_count;

    public:

        WeakPointer(): m_ptr(nullptr), m_count(nullptr){}

        WeakPointer(const SharePointer<T>& s_ptr){
            m_ptr = s_ptr.m_ptr;
            m_count = s_ptr.m_count;
            if(m_count)
                *m_count ++;
        }

        WeakPointer(const WeakPointer<T>& other){
            m_ptr = other.m_ptr;
            m_count = other.m_count;
            if(m_count)
                *m_count ++;
        }
        
        ~WeakPointer(){
            reset();
        }

        void reset() {
            if (m_count) {
                (*m_count)--;
                if (*m_count == 0) {
                    delete m_ptr;
                    delete m_count;
                }
            }
            m_ptr = nullptr;
            m_count = nullptr;
        }

        //nếu Weak ptr tồn tại trả về share ptr sở hữu (địa chỉ), nếu ko tồn tại trả về default nullptr
        SharePointer<T> lock() const{
            return SharePointer<T> (*this);
        }

        // trả về số lượng share_ptr chia sẽ quyền sở hữu
        unsigned int use_count() const{
            return *m_count;
        }
        
        WeakPointer<T>& operator = (const SharePointer<T>& other){
            if(this != &other){
                reset();
                m_ptr = other.m_ptr;
                m_count = other.m_count;
                if (m_count) 
                    (*m_count)++;
            }
            return *this;
        }

        
        T& operator * () const {
            return *m_ptr;
        }

        T& operator -> () const {
            return m_ptr;
        }

        friend class SharePointer<T>;

};


#endif