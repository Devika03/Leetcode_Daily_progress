class ParkingSystem {
public:
    int big,medium,small;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType==1 and big==0 || carType==2 and medium==0 || carType==3 and small == 0){
            return false;
        }
        if(carType ==1){ 
            big-- ;}
        if(carType == 2){
            medium--;
        }
        if(carType ==3){
            small--;
        }
        return true;
    }
};
