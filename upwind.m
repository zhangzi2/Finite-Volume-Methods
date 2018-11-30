function [q_0] = q_0(x)
        if x <= 1
            q_0 = 1;
        else
            q_0 = 0;
        end
    end

    function [q_true] = q_true(x,t)
        if x-t <= 1
            q_true = 1;
        else
            q_true = 0;
        end
    end

    function [] = upwind(a,b,dx,max_t,dt)
        
        space = a:dx:b; 
        time = 0:dt:max_t;
        
        true_0=zeros(1,length(space));
        true_20=zeros(1,length(space));
        true_40=zeros(1,length(space));
        for j=1:length(space)
            true_0(j) = q_true(space(j),0);
            true_20(j) = q_true(space(j),20);
            true_40(j) = q_true(space(j),40);
        end

        Q=zeros(1,length(space));
        for j=1:length(space)
           Q(j) = q_0(space(j));
        end
        
        subplot(3,1,1)
        plot(space, Q, 'o');hold on;
        plot(space,true_0);hold on;
        title('t=0'); legend('upwind approximation', 'true solution');
        
        F=zeros(1,length(space)+1);
        F(1) = 1;
        for i=2:length(Q)+1
                F(i) = Q(i-1);
        end
        for j=2:length(time)
            Q(1) = 1;
            for k=2:length(Q)
               Q(k) = Q(k) + (dt/dx)*(F(k)-F(k+1));
               %Q(k) = Q(k) + (dt/dx)*(Q(k-1)-Q(k)); %this one also works 
            end
            for i=2:length(Q)+1
                F(i) = Q(i-1);
            end
            
            if time(j) == 20 
                subplot(3,1,2)
                plot(space,Q,'o');hold on;
                plot(space,true_20);hold on;
                title('t=20'); legend('upwind approximation', 'true solution');
            end
            if time(j) == 40
                subplot(3,1,3)
                plot(space,Q,'o');hold on;
                plot(space,true_40);hold on;
                title('t=40'); legend('upwind approximation', 'true solution');
            end
            
        end
end
    
