fileID = fopen('Output.txt','r');
formatSpec = '%f';
A = fscanf(fileID,formatSpec);

fileID = fopen('Error.txt','r');
formatSpec = '%f';
B = fscanf(fileID,formatSpec);

fileID = fopen('Ref.txt','r');
formatSpec = '%f';
C = fscanf(fileID,formatSpec);

dt=0.1;
T=size(A)*dt;
t=(0.1:dt:T);

figure()
plot(t,A);
hold
plot(t,C,'r');
title('Control Input');
ylim([0 10]);
xlabel('time');
ylabel('Control/Reference');


figure()
plot(t,B,'r');
title('Error');
xlabel('time');
ylabel('Error value');



