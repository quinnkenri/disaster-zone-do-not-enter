% Grade Calculator for GE-172
% Calculates final GE-172 grade based on USask RLO/CLO criteria
% Created by: Quinn Lawson
% Last modified: October 11, 2024

clc;
clear;

% Prompts for user to input their grades
rlo1_1 = input('Input RLO 1.1 Grades as a vector: ');
rlo2_1 = input('Input RLO 2.1 Grades as a vector: ');
rlo2_2 = input('Input RLO 2.2 Grades as a vector: ');
rlo3_1 = input('Input RLO 3.1 Grades as a vector: ');
rlo4_1 = input('Input RLO 4.1 Grades as a vector: ');
rlo4_2 = input('Input RLO 4.2 Grades as a vector: ');
rlo5_1 = input('Input RLO 5.1 Grades as a vector: ');

% Take average for Type A/Type C RLOs, initialize variables for Type B/B+
finalrlo1_1 = mean(rlo1_1);
finalrlo2_1 = rlo2_1(1);
finalrlo2_2 = rlo2_2(1);
finalrlo3_1 = rlo3_1(1);
finalrlo4_1 = rlo4_1(1);
finalrlo4_2 = rlo4_2(1);
finalrlo5_1 = mean(rlo5_1);

% For loop to calculate Type B/B+ RLO final grade of RLO 2.1
for i=1:(length(rlo2_1)-1)
    if rlo2_1(i+1) >= rlo2_1(i) 
    finalrlo2_1 = rlo2_1(i+1); % replace earlier grade if later grade is higher
    else 
    finalrlo2_1 = ((finalrlo2_1*.4)+(rlo2_1(i+1)*.6)); % weighted average if later grade is lower
    end
end

% Same loop for RLO 2.2
for i=1:(length(rlo2_2)-1)
    if rlo2_2(i+1) >= rlo2_2(i) 
    finalrlo2_2 = rlo2_2(i+1);
    else 
    finalrlo2_2 = ((finalrlo2_2*.4)+(rlo2_2(i+1)*.6)); 
    end
end

% Same loop for RLO 3.1
for i=1:(length(rlo3_1)-1)
    if rlo3_1(i+1) >= rlo3_1(i) 
    finalrlo3_1 = rlo3_1(i+1);
    else 
    finalrlo3_1 = ((finalrlo3_1*.4)+(rlo3_1(i+1)*.6));
    end
end

% Same loop for RLO 4.1
for i=1:(length(rlo4_1)-1)
    if rlo4_1(i+1) >= rlo4_1(i) 
    finalrlo4_1 = rlo4_1(i+1);
    else 
    finalrlo4_1 = ((finalrlo4_1*.4)+(rlo4_1(i+1)*.6));
    end
end

% Same loop for RLO 4.2
for i=1:(length(rlo4_2)-1)
    if rlo4_2(i+1) >= rlo4_2(i) 
    finalrlo4_2 = rlo4_2(i+1);
    else 
    finalrlo4_2 = ((finalrlo4_2*.4)+(rlo4_2(i+1)*.6));
    end
end

% Round off RLO grades before turning them into CLO grades
clo1 = round(finalrlo1_1);
clo2 = round((finalrlo2_1*.25)+(finalrlo2_2*.75)); % weighted in GE-172 syllabus
clo3 = round(finalrlo3_1);
clo4 = round((finalrlo4_1*.7)+(finalrlo4_2*.3)); % weighted in GE-172 syllabus
clo5 = round(finalrlo5_1);

% Calculate final course grade based on weighting in syllabus
coursegrade = (clo1*.05)+(clo2*.4)+(clo3*.1)+(clo4*.3)+(clo5*.15);

% Cap grade at 49 if student cannot achieve 70% in Type B and 50% in Type B+
% However, if the course grade is already below 49, do not raise it
if ((clo2 < 70) || (clo3 < 70) || (clo4 < 50)) && (coursegrade > 49)
    coursegrade = 49;
end

% If statement to print different message if student passes or fails
if coursegrade < 50
    fprintf(['\n\nYour final grade is %d. Unfortunately, you did not pass GE-172.\n\nHere is a breakdown ' ...
        'of your grade:\nCLO 1 Final Grade: %d \nCLO 2 Final Grade: %d \nCLO 3 Final Grade: %d ' ...
        '\nCLO 4 Final Grade: %d \nCLO 5 Final Grade: %d\n', coursegrade, clo1, clo2, clo3, clo4, clo5]);
else

fprintf(['\n\nYour final grade is %d. Congratulations, you have passed GE-172!' ...
    '\nHere is a breakdown of your grade:\nCLO 1 Final Grade: %d \nCLO 2 Final Grade: %d \nCLO 3 Final Grade: %d ' ...
        '\nCLO 4 Final Grade: %d \nCLO 5 Final Grade: %d\n', coursegrade, clo1, clo2, clo3, clo4, clo5])
end
