#ifndef PEDESTRIAN_H
#define PEDESTRIAN_H


class Pedestrian
{
    public:
        Pedestrian(double posX, double posY, double vX0, double vY0);
        double getVelocityX();
        double getVelocityY();
        double getPositionX();
        double getPositionY();
        void setVelocityX(double vX);
        void setVelocityY(double vY);
        void setPositionX(double posX);
        void setPositionY(double posY);

    protected:

    private:
        double velocity[2];
        double position[2];
};

#endif // PEDESTRIAN_H
