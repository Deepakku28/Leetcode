class ParkingSystem {
public:
    vector<int> num;
    
    ParkingSystem(int big, int medium, int small) {
        num.clear();
        num={big,medium,small};
    }
    
    bool addCar(int carType) {
        if(num[carType-1]){
            num[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
