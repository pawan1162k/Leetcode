class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=abs(ay2-ay1)*abs(ax2-ax1);
        int area2=abs(by2-by1)*abs(bx2-bx1);
        int x=0;
        int y=0;
        x=(min(ax2,bx2)-max(ax1,bx1));
        y=(min(ay2,by2)-max(ay1,by1));
        if(x>0 && y>0){
            return area1+area2-(x*y); 
        }
        return area1+area2;
        
        
    }
};