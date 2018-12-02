function [] = upwind(a,b,dx,max_t,dt)
        %initial conditions
        function [q_0] = q_0(x)
            if x <= 1
                q_0 = 1;
            else
                q_0 = 0;
            end
        end
        %initialize space and time
        space = a:dx:b; 
        time = 0:dt:max_t;       
        %initialize Q
        Q=zeros(1,length(space));
        for j=1:length(space)
           Q(j) = q_0(space(j));
        end
        %initialize flux
        F=zeros(1,length(space)+1);
        F(1) = 1;
        for i=2:length(Q)+1
                F(i) = Q(i-1);
        end
        %step through time
        for j=2:length(time)
            Q(1) = 1;
            for k=2:length(Q)
               Q(k) = Q(k) + (dt/dx)*(F(k)-F(k+1));
               %Q(k) = Q(k) + (dt/dx)*(Q(k-1)-Q(k)); %this one also works 
            end
            for i=2:length(Q)+1
                F(i) = Q(i-1);
            end
            
        end

    end