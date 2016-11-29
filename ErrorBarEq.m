err = .1:.05:2;
err = [err,3:1:110];
bar_percent = zeros(1,length(err));

for i=1:length(err)
    if (err(i) > 100)
        bar_percent(i) = 0;
    elseif (err(i)>5)
        bar_percent(i) = -0.7895*err(i)+79;
    else
        bar_percent(i) = -5.55*err(i)+102.78;
    end
end

plot(err,bar_percent)