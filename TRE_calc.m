% Insertion To0l Fiducial geometry
mk1 = [-20 -10 0]';
mk2 = [65 30 0]';
mk3 = [65 150 0]';
mk4 = [-20 150 0]';

X = [mk1 mk2 mk3 mk4];
T = [21.575 -152 -10]'; % cochlea entrance
RMS_FLE = 0.25;  % Polaris 95% confidence

TRE_RMS = TREapprox(X,T,RMS_FLE);