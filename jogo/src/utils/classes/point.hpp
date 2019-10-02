
class Point {

    private:
        int x;
        int y;
    
    public:
        Point();
        Point(int xx, int yy) : x{xx}, y{yy} {}

        int getX() { return x; }
        void setX(int xx) { x = xx; }
        int getY() { return y; }
        void setY(int yy) { y = yy; }

        void operator += (const Point& p) { x += p.x; y += p.y; }
};