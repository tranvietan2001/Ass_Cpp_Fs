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
        //constructor khởi tạo mặt định, gắn bằng null
        // SharePointer(): m_ptr(nullptr), m_count(nullptr){}

        // constructor khi khỏi tạo obj thì tạo 1 con trỏ null và biến đếm tham chiếu = 1
        SharePointer(T* ptr = nullptr): m_ptr(ptr), m_count(new int(1)){}

        // copy constructor tạo 1 share ptr từ 1 share ptr đã tồn tại
        SharePointer(const SharePointer<T>& sp) : m_ptr(sp.m_ptr), m_count(sp.m_count) {
            if (m_count) {
                (*m_count)++;
            }
        }

        // copy constructor chuyển đổi Weak ptr thành Share ptr
        SharePointer(const WeakPointer<T>& w_ptr): m_ptr(w_ptr.m_ptr), m_count(w_ptr.m_count){
            if (m_count) {
                (*m_count)++;
            }
        } 
        // destructor được gọi tự động khi ojb bị hủy hoặc ra khỏi scope
        ~SharePointer(){
            reset();
        }

        // trả về số lượng tham chiếu đến obj mà share ptr trỏ tới
        unsigned int use_count() const{
            if(m_count)
                return *m_count;
            else return 0;
        }

        // trả về con trỏ trỏ tới đối tượng mà share ptr quản lý
        T* get() const { 
        return m_ptr; 
        }
        
        // giảm count đi 1 nếu reset obj, nếu cout về 0 thì giải phóng các đối tượng quản lý ptr và count
        void reset() {
            if (m_count) { //m_count != nullptr
                (*m_count)--;
                if (*m_count == 0) { // không còn obj share ptr nào tham chiếu đến obj mà m_ptr trỏ tới.
                    delete m_ptr;
                    delete m_count;
                }
            }
            m_ptr = nullptr;
            m_count = nullptr;
        }

        //Kiểm tra xem chỉ có một shared_ptr sở hữu đối tượng hay không (use_cout = 1).
        bool unique(){
            if(m_ptr && (*m_count == 1))
                return true;
            else return false;
        }

        // hoán đổi nội dung của 2 dối tượng share ptr p1 <=> p2
        void swap(SharePointer<T>& other) {
            std::swap(m_ptr, other.m_ptr);
            std::swap(m_count, other.m_count);
        }
        
        // gán share ptr mới bằng share ptr hiện tại : vd share_ptr p2 = p1
        SharePointer<T>& operator = (const SharePointer<T>& other){
            if(this != &other){             // kiểm tra this và other có cùng trỏ tới 1 obj ko, nếu ko thì gắn =
                reset();                    // giải phóng obj mà dhare ptr đang quản lý
                m_ptr = other.m_ptr;
                m_count = other.m_count;
                if (m_count)                // ktra share ptr có trỏ đến obj đã cấp phát hay không (m_ptr != nullptr)
                    (*m_count)++;           // tăng cout 1 -> biểu thị có 1 tham chiếu khác đến obj
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

        //constructor khởi tạo mặt định, gắn = nullptr
        // WeakPointer(): m_ptr(nullptr), m_count(nullptr){}

        //copy constructor: khởi tạo obj weal ptr từ share ptr đã có, tạo ra 1 weak trỏ tới cùng 1 obj share ptr quản lý
        WeakPointer(const SharePointer<T>& s_ptr): m_ptr(s_ptr.m_ptr), m_count(s_ptr.m_count){
            // if(m_count)        // ==>>>lỗi: count của weak ko xác định
            //     *m_count ++;
        }
        
        //copy constructor: copy constructor tạo 1 weak ptr từ 1 weak ptr đã tồn tại
        WeakPointer(const WeakPointer<T>& other): m_ptr(other.m_ptr), m_count(other.m_count){
            if(m_count)
                *m_count ++;
        }

        // destructor được gọi tự động khi ojb bị hủy hoặc ra khỏi scope
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
        // unsigned int use_count() const{
        //     return *m_count;
        // }

        unsigned int use_count() const{
            if(m_count)
                return *m_count;
            else return 0;
        }
        
        //kiểm tra WeakPointer có hết hạn hay không, hết hạn khi con trỏ m_count trỏ đến nullptr hoặc giá trị mà m_count trỏ tới bằng 0
        bool expired() const {
                return (m_count == nullptr) || (*m_count == 0);
        }
        
        // hoán đổi 2 weakpointer
        void swap(WeakPointer<T>& other) noexcept {
            std::swap(m_ptr, other.m_ptr);
            std::swap(m_count, other.m_count);
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