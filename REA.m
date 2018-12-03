 function [] = REA(a,b,dx,max_t,dt)
        function [sigma] = minmod(a,b,c)
           A = [a,b,c];
           if sign(a) + sign(b) + sign(c) == 3
               sigma = min(A);
           elseif sign(a) + sign(b) + sign(c) == -3
               sigma = max(A);
           else
               sigma = 0;
           end
        end
        function [f] = f(x)
            if x<5 && x>(-1*5)
                f = 1;
            else
                f = 0;
            end
        end

        function [u] = u(x)
            u = 0.03*x; 
        end
        %initialize space, time
        space = a:dx:b;   
        space = space(2:end-1); %trim space
        time = 0:dt:max_t;

        %initialize Q
        Q=zeros(1,length(space));
        for j=1:length(space)
           Q(j) = f(space(j));
        end

        %initialize flux
        F=zeros(1,length(Q)+1);
        %F(1) = u(Q(1));
        F(1) = u(space(1))*Q(1);
        F(2) = u(space(2))*Q(2); %upwind
        for i=3:length(Q)-1
            if u(space(i)) > 0
                sigma = minmod((Q(i)-Q(i-2))/(2*dx), 2*(Q(i-1)-Q(i-2))/dx, 2*(Q(i)-Q(i-1))/dx);
                F(i) = u(space(i))*Q(i-1)+0.5*u(space(i))*(dx-u(space(i))*dt)*sigma;
            else
                sigma = minmod((Q(i+1)-Q(i-1))/(2*dx), 2*(Q(i)-Q(i-1))/dx, 2*(Q(i+1)-Q(i))/dx);
                F(i) = u(space(i))*Q(i)+0.5*abs(u(space(i)))*(dx-abs(u(space(i))*dt))*sigma;
            end
        end
        F(length(Q)) = u(space(end-1))*Q(end-1); %upwind
        F(end) = u(space(end))*Q(end);
        %F(length(Q)+1) = u(Q(end));        
        %step through time
        for t = 2:length(time)
           for k=1:length(Q)
               Q(k) = Q(k) + (dt/dx)*(F(k)-F(k+1));
           end
           %F(1) = u(Q(1));
           F(1) = u(space(1))*Q(1);
           F(2) = u(space(2))*Q(2);
           for i=3:length(Q)-1
                if u(space(i)) > 0
                    sigma = minmod((Q(i)-Q(i-2))/(2*dx), 2*(Q(i-1)-Q(i-2))/dx, 2*(Q(i)-Q(i-1))/dx);
                    F(i) = u(space(i))*Q(i-1)+0.5*u(space(i))*(dx-u(space(i))*dt)*sigma;
                else
                    sigma = minmod((Q(i+1)-Q(i-1))/(2*dx), 2*(Q(i)-Q(i-1))/dx, 2*(Q(i+1)-Q(i))/dx);
                    F(i) = u(space(i))*Q(i)+0.5*abs(u(space(i)))*(dx-abs(u(space(i))*dt))*sigma;
                end
           end
           F(length(Q)) = u(space(end-1))*Q(end-1);
           F(end) = u(space(end))*Q(end);
        end
    end