%% Edit by  XXX
%这个代码用于做 moudle 19 的 data1—5的 图 的。
%方法是 在 工作区 新建一个变量 A  。然后将要处理的某一个data的数据复制粘贴过去（要注意保证一共有偶数行）。
%然后全选这些代码，右键执行。
%% 
[r,c] = size(A);%
LEDdata  = zeros(r/2,1);
 Ambientdata= zeros(r/2,1);
 k = 1;
 z = 1;
 
 %%  这里的两个循环。意思是分别把A中的奇数行和偶数行放入到两个新的列中。
for i =2:2:r
    LEDdata(k,1) =  A (i,1);
    k = k+1;
end
for i =1:2:r 
    Ambientdata(z,1) = A(i,1);
    z = z +1 ;
end
%%
x = LEDdata;
y = Ambientdata;
plot(x,y)
%% 
title('data 4') %这里可以改一下图的名字
xlabel('LEDdata');
ylabel('Ambientdata');
legend('LEDdata');
%%
% 这些代码参考一下就好啦
