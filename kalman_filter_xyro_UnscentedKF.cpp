#include <iostream>
#include <vector>
#include "Eigen/Dense"

class Unscented_KF{
    public:
        Unscented_KF(double sampling_time, double _kappa, Eigen::MatrixXd _P, Eigen::MatrixXd _Q, Eigen::MatrixXd _R, int _num_state, int _num_measured ){
            dt = sampling_time;
            P = _P;
            Q = _Q;
            R = _R;
            kappa = _kappa;

            num_state = _num_state;
            num_measured = _num_measured;

            X = Eigen::VectorXd::Zero(num_state);
        }

        void SigmaPoints_WeightSelect(){
            Xi = Eigen::MatrixXd::Zero(num_state, 2*num_state + 1); // state 마다 2*num_state + 1 개의 샘플을 생성
            W  = Eigen::MatrixXd::Zero(2*num_state+1, 1);

            for(int i = 0; i < num_state ; ++i){
                Xi(i, 0) = X(i);
            }
            W(0) = kappa / (num_state + kappa);

            Eigen::LLT<Eigen::MatrixXd> _U((num_state+kappa)*P);
            Eigen::MatrixXd U_ = _U.matrixL();

            // right
            for(int i =0 ; i < num_state; ++i){
                for(int j =0 ; j < num_state; ++j){
                    Xi(i,j+1) = X(i) + U_(j,i).transpose();
                    W(j+1) = 1/(2*(num_state + kappa));
                }
            } 

            // left
            for(int i =0 ; i < num_state; ++i){
                for(int j =0 ; j < num_state; ++j){
                    Xi(i,j+num_state+1) = X(i) - U_(j,i).transpose();
                    W(j+num_state+1) = 1/(2*(num_state + kappa));
                }
            } 
        }

        void Predict(){






        }
        void KalmanGainCalculation();
        void Update(Eigen::Vector measured);

    private:
        double dt;
        double kappa;
        Eigen::MatrixXd P, Q, R;
        Eigen::VectorXd X;
        int num_state, num_measured;

        /**
         * @brief Sigma Points and Weight 
         */
        Eigen::MatrixXd Xi;
        Eigen::MatrixXd W;

        /**
         * @brief 
         */
        



        Eigen::VectorXd system_process(Eigen::VectorXd X_in, Eigen::VectorXd measured){
            double phi = X_in(0), theta = X_in(1);
            double p = measured(0), q = measured(2), r = measured(3);
            double x_dot1, x_dot2, x_dot3;

            x_dot1 = p + q*sin(phi) * tan(theta) + r*cos(phi)*tan(theta);
            x_dot2 =     q*cos(phi)              - r*sin(phi);
            x_dot3 =     q*sin(phi)*(1.0)/cos(theta) + r*cos(phi)*(1.0)/cos(theta);

            Eigen::VectorXd Xdot = Eigen::VectorXd::Zero(num_state);
            Xdot << x_dot1, x_dot2, x_dot3;

            Eigen::VectorXd Xp = X + Xdot * dt;
            return Xp
        };

        Eigen::VectorXd output_equation(Eigen::VectorXd X_in){
            double yp1, yp2;
            yp1 = X_in(0);
            yp2 = X_in(1);

            Eigen::VectorXd Yp = Eigen::VectorXd::Zero(num_measured);
            Yp << yp1, yp2;

            return Yp;
        }

        

        std::vector<Eigen::MatrixXd> UnscentedTransform(Eigen::MatrixXd Xi_in , Eigen::Matrix noiseCov){

            int n = Xi_in.rows();
            int kmax = Xi_in.cols();

            Eigen::MatrixXd xm = Eigen::MatrixXd::Zero(n,1);
            for (int i = 0 ; i < n ; ++i){
                for (int k =0 ; k < kmax; ++k){
                    xm(i,0) = xm(i,0) + W(k) * Xi_in(i,k);
                }
            }

            Eigen::MatrixXd xcov = Eigen::Matrix::Zero(n, n);
            for(int i =0 ; i < n ; ++i){
                for (int k =0 ; k < kmax ; ++k){
                    xcov(i,k) = xcov(i,k) + W(k) * (Xi_in(i,k) - xm(i,0))* (Xi_in(i,k)-xm(i,0)).transpose(); 
                }
            }

            xcov = xcov + noiseCov;

            std::vector<Eigen::MatrixXd> ret = {xm, xcov};
            return ret;
        }
};

