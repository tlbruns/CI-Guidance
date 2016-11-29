% Similarity transformation matrix to rotate from Polaris frame

% Fixed-frame rotation-> y(pi), then z(pi/2)
% Thus premultiply-> z(pi/2)*y(pi)

T_z = [0 -1 0 0; 
       1 0 0 0; 
       0 0 1 0; 
       0 0 0 1];
     
T_y = [-1 0 0 0;
       0 1 0 0;
       0 0 -1 0;
        0 0 0 1];
T_Pol_sim = T_z*T_y
T_inv = inv(T_Pol_sim)
