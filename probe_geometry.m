% coordinates in Polaris Frame
mk1 = [-242.98, -44.02, 9.85]';
mk2 = [-211.98, -78.88, 28.46]';
mk3 = [-122.57, -35.61, 13.53]';

T_mk1 = [eye(3),mk1; 0,0,0,1];
T_mk2 = [eye(3),mk2; 0,0,0,1];
T_mk3 = [eye(3),mk3; 0,0,0,1];

T_Pol_sim = [0,-1,0,0;-1,0,0,0;0,0,-1,0;0,0,0,1];

% coordinates in screen frame
mk1_adj = T_Pol_sim*T_mk1*inv(T_Pol_sim);
mk2_adj = T_Pol_sim*T_mk2*inv(T_Pol_sim);
mk3_adj = T_Pol_sim*T_mk3*inv(T_Pol_sim);