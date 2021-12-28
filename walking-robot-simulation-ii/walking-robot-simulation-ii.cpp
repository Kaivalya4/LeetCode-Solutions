class Robot {
public:
    int w , h;
    int peri;
    int x , y;
    string dir = "East";
    Robot(int width, int height) {
        w = width;
        h = height;
        x=0, y=0;
        peri = (w+h-2)*2;
    }
    
    void step(int num) {
        num %= peri;
        if(num == 0 && x==0 && y == 0)
            dir = "South";
        while(num--)
        {
            if(dir=="East"){
                if(x+1>=w){
                    dir="North";
                    y++;
                }
                else x++;
            }
            else if(dir=="West"){
                if(x-1<0){
                   dir="South";
                   y--;
                } 
                else x--;
            }
            else if(dir=="South"){
                if(y-1<0){
                    dir="East";
                    x++;
                }
                else y--;
            }
            else if(dir=="North"){
                if(y+1>=h){
                    dir="West";
                    x--;
                }
                else y++;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */