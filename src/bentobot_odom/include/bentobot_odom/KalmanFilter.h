#pragma once

#include <eigen3/Eigen/Dense>

class KalmanFilter {
    public:
        KalmanFilter(
            Eigen::Matrix<double, 5, 5> process_noise_cov,
            Eigen::Matrix<double, 2, 2> odom_noise_cov,
            Eigen::Matrix<double, 1, 1> imu_noise_cov);

        void stateTransitionUpdate(double dt);
        void measurementOdomUpdate(double v, double w);
        void measurementIMUUpdate(double w);

    private:
        Eigen::Matrix<double, 5, 5> linearizeStateTransitionMatrix(double dt);
        
        Eigen::Matrix<double, 5, 1> state;
        Eigen::Matrix<double, 5, 5> covariance;

        Eigen::Matrix<double, 2, 5> C_odom;
        Eigen::Matrix<double, 1, 5> C_imu;

        const Eigen::Matrix<double, 5, 5> process_noise_cov;
        const Eigen::Matrix<double, 2, 2> odom_noise_cov;
        const Eigen::Matrix<double, 1, 1> imu_noise_cov;
};