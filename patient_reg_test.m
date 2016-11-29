% Y -> baseline data points
mk1 = [35.2, -221.9, 1604];
mk2 = [103.6, -217.3, 1594.2];
mk3 = [61.4, -222.2, 1539.3];
mk1_line = [mk1;mk2];
mk2_line = [mk2;mk3];
mk3_line = [mk3;mk1];

% X-> test data points to register
test_mk1 = [246.4,-441.1,1383.4];
test_mk2 = [182.9,-418.2,1400.2];
test_mk3 = [197.6,-435.1,1333.8];
test_mk1_line = [test_mk1;test_mk2];
test_mk2_line = [test_mk2;test_mk3];
test_mk3_line = [test_mk3;test_mk1];

figure(1)
hold on
axis equal
plot3(mk1_line(:,1),mk1_line(:,2), mk1_line(:,3),'r')
plot3(mk2_line(:,1),mk2_line(:,2), mk2_line(:,3),'r')
plot3(mk3_line(:,1),mk3_line(:,2), mk3_line(:,3),'r')
plot3(test_mk1_line(:,1),test_mk1_line(:,2), test_mk1_line(:,3),'g')
plot3(test_mk2_line(:,1),test_mk2_line(:,2), test_mk2_line(:,3),'g')
plot3(test_mk3_line(:,1),test_mk3_line(:,2), test_mk3_line(:,3),'g')

X = [test_mk1',test_mk2',test_mk3'];
Y = [mk1',mk2',mk3'];
[R,t,FRE,FREcomponents] = point_register(X,Y);

X_registered = R*X + t*ones(1,3);
registered_mk1 = X_registered(:,1)';
registered_mk2 = X_registered(:,2)';
registered_mk3 = X_registered(:,3)';
registered_mk1_line = [registered_mk1;registered_mk2];
registered_mk2_line = [registered_mk2;registered_mk3];
registered_mk3_line = [registered_mk3;registered_mk1];

figure(2)
axis equal
hold on
plot3(mk1_line(:,1),mk1_line(:,2), mk1_line(:,3),'r')
plot3(mk2_line(:,1),mk2_line(:,2), mk2_line(:,3),'r')
plot3(mk3_line(:,1),mk3_line(:,2), mk3_line(:,3),'r')
plot3(registered_mk1_line(:,1),registered_mk1_line(:,2), registered_mk1_line(:,3),'g')
plot3(registered_mk2_line(:,1),registered_mk2_line(:,2), registered_mk2_line(:,3),'g')
plot3(registered_mk3_line(:,1),registered_mk3_line(:,2), registered_mk3_line(:,3),'g')
title(sprintf('Registered with RMS FRE of %1.3f', FRE))

% calculate estimated TRE using microtable data
Mastoid = [86.8336  143.8835   74.5270]';
Posterior = [125.8017  106.6108   74.3388]';
Superior = [127.0397  180.2254   75.8322]';
Target = [123.9691  144.3232  125.4670]';
Entry = [123.6132  144.5476  122.2636]';
microtable = [Mastoid Superior Posterior];
RMS_FLE = 0.15;
TRE_RMS = TREapprox(microtable,Target,RMS_FLE);
MP = [Mastoid Posterior]';
PS = [Posterior Superior]';
SM = [Superior Mastoid]';
ET = [Entry Target]';

figure(3)
hold on
axis equal
plot3(MP(:,1),MP(:,2), MP(:,3),'r')
plot3(PS(:,1),PS(:,2), PS(:,3),'r')
plot3(SM(:,1),SM(:,2), SM(:,3),'r')
plot3(ET(:,1),ET(:,2), ET(:,3),'b')

% Register microtable data to the first
[R,t,FRE,FREcomponents] = point_register(microtable,Y);

microtable_registered = R*microtable + t*ones(1,3);
target_reg = R*Target+t;
entry_reg = R*Entry+t;
ET_reg = [entry_reg target_reg]';
microtable_registered_mk1 = microtable_registered(:,1)';
microtable_registered_mk2 = microtable_registered(:,2)';
microtable_registered_mk3 = microtable_registered(:,3)';
microtable_registered_mk1_line = [microtable_registered_mk1;microtable_registered_mk2];
microtable_registered_mk2_line = [microtable_registered_mk2;microtable_registered_mk3];
microtable_registered_mk3_line = [microtable_registered_mk3;microtable_registered_mk1];

figure(4)
axis equal
hold on
plot3(ET_reg(:,1),ET_reg(:,2),ET_reg(:,3),'b')
plot3(mk1_line(:,1),mk1_line(:,2), mk1_line(:,3),'r')
plot3(mk2_line(:,1),mk2_line(:,2), mk2_line(:,3),'r')
plot3(mk3_line(:,1),mk3_line(:,2), mk3_line(:,3),'r')
plot3(microtable_registered_mk1_line(:,1),microtable_registered_mk1_line(:,2), microtable_registered_mk1_line(:,3),'g')
plot3(microtable_registered_mk2_line(:,1),microtable_registered_mk2_line(:,2), microtable_registered_mk2_line(:,3),'g')
plot3(microtable_registered_mk3_line(:,1),microtable_registered_mk3_line(:,2), microtable_registered_mk3_line(:,3),'g')
title(sprintf('Registered with RMS FRE of %1.3f', FRE))