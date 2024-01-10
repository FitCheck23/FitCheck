#include "desktop.h"
#include "ui_desktop.h"

#include <QtMath> // Include QtMath for trigonometric functions
#include <QList>
#include <cmath>


void Desktop::setAllPosesAngles()
{



    QVector<float> Chair_Pose;
    Chair_Pose.push_back(168);
    Chair_Pose.push_back(166);
    Chair_Pose.push_back(174);
    Chair_Pose.push_back(175);
    Chair_Pose.push_back(176);
    Chair_Pose.push_back(179);
    Chair_Pose.push_back(178);
    Chair_Pose.push_back(177);

    allPosesAngles.insert("Chair_Pose", Chair_Pose);


    QVector<float> Flamingo_Pose;
    Flamingo_Pose.push_back(175);
    Flamingo_Pose.push_back(176);
    Flamingo_Pose.push_back(46);
    Flamingo_Pose.push_back(51);
    Flamingo_Pose.push_back(85);
    Flamingo_Pose.push_back(82);
    Flamingo_Pose.push_back(88);
    Flamingo_Pose.push_back(90);

    allPosesAngles.insert("Flamingo_Pose", Flamingo_Pose);


    QVector<float> Goddess_Pose;
    Goddess_Pose.push_back(91);
    Goddess_Pose.push_back(83);
    Goddess_Pose.push_back(80);
    Goddess_Pose.push_back(79);
    Goddess_Pose.push_back(107);
    Goddess_Pose.push_back(103);
    Goddess_Pose.push_back(111);
    Goddess_Pose.push_back(108);

    allPosesAngles.insert("Goddess_Pose", Goddess_Pose);

    QVector<float> Half_Moon_Pose;
    Half_Moon_Pose.push_back(161);
    Half_Moon_Pose.push_back(165);
    Half_Moon_Pose.push_back(157);
    Half_Moon_Pose.push_back(150);
    Half_Moon_Pose.push_back(162);
    Half_Moon_Pose.push_back(165);
    Half_Moon_Pose.push_back(178);
    Half_Moon_Pose.push_back(178);

    allPosesAngles.insert("Half_Moon_Pose", Half_Moon_Pose);


    QVector<float> Mountain_Pose;
    Mountain_Pose.push_back(176);
    Mountain_Pose.push_back(175);
    Mountain_Pose.push_back(163);
    Mountain_Pose.push_back(165);
    Mountain_Pose.push_back(177);
    Mountain_Pose.push_back(179);
    Mountain_Pose.push_back(177);
    Mountain_Pose.push_back(178);

    allPosesAngles.insert("Mountain_Pose", Mountain_Pose);


    QVector<float> T_Pose;
    T_Pose.push_back(179);
    T_Pose.push_back(179);
    T_Pose.push_back(95);
    T_Pose.push_back(97);
    T_Pose.push_back(174);
    T_Pose.push_back(172);
    T_Pose.push_back(179);
    T_Pose.push_back(176);

    allPosesAngles.insert("T_Pose", T_Pose);


    QVector<float> Tree_Pose_1;
    Tree_Pose_1.push_back(91);
    Tree_Pose_1.push_back(89);
    Tree_Pose_1.push_back(150);
    Tree_Pose_1.push_back(160);
    Tree_Pose_1.push_back(111);
    Tree_Pose_1.push_back(174);
    Tree_Pose_1.push_back(39);
    Tree_Pose_1.push_back(166);

    allPosesAngles.insert("Tree_Pose_1", Tree_Pose_1);


    QVector<float> Tree_Pose_2;
    Tree_Pose_2.push_back(174);
    Tree_Pose_2.push_back(169);
    Tree_Pose_2.push_back(137);
    Tree_Pose_2.push_back(118);
    Tree_Pose_2.push_back(175);
    Tree_Pose_2.push_back(118);
    Tree_Pose_2.push_back(177);
    Tree_Pose_2.push_back(23);

    allPosesAngles.insert("Tree_Pose_2", Tree_Pose_2);


    QVector<float> Warrior_Pose;
    Warrior_Pose.push_back(171);
    Warrior_Pose.push_back(179);
    Warrior_Pose.push_back(100);
    Warrior_Pose.push_back(98);
    Warrior_Pose.push_back(150);
    Warrior_Pose.push_back(130);
    Warrior_Pose.push_back(174);
    Warrior_Pose.push_back(118);

    allPosesAngles.insert("Warrior_Pose", Warrior_Pose);


}

float Desktop::calculateScore(PoseData landmarks)
{
    LastDataDateTime = QDateTime::currentDateTime();

    QVector<float> right_elbow;
    QVector<float> left_elbow;
    QVector<float> right_shoulder;
    QVector<float> left_shoulder;
    QVector<float> right_wrist;
    QVector<float> left_wrist;
    QVector<float> right_hip;
    QVector<float> left_hip;
    QVector<float> right_knee;
    QVector<float> left_knee;
    QVector<float> right_ankle;
    QVector<float> left_ankle;


    QVector<float> angle_point;

    right_elbow.push_back(landmarks.vectors[14].x);
    right_elbow.push_back(landmarks.vectors[14].y);
    right_elbow.push_back(landmarks.vectors[14].z);
    right_elbow.push_back(QString::number(landmarks.vectors[14].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(right_elbow);

    left_elbow.push_back(landmarks.vectors[13].x);
    left_elbow.push_back(landmarks.vectors[13].y);
    left_elbow.push_back(landmarks.vectors[13].z);
    left_elbow.push_back(QString::number(landmarks.vectors[13].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(left_elbow);

    right_shoulder.push_back(landmarks.vectors[12].x);
    right_shoulder.push_back(landmarks.vectors[12].y);
    right_shoulder.push_back(landmarks.vectors[12].z);
    right_shoulder.push_back(QString::number(landmarks.vectors[12].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(right_shoulder);

    left_shoulder.push_back(landmarks.vectors[11].x);
    left_shoulder.push_back(landmarks.vectors[11].y);
    left_shoulder.push_back(landmarks.vectors[11].z);
    left_shoulder.push_back(QString::number(landmarks.vectors[11].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(left_shoulder);

    right_wrist.push_back(landmarks.vectors[16].x);
    right_wrist.push_back(landmarks.vectors[16].y);
    right_wrist.push_back(landmarks.vectors[16].z);
    right_wrist.push_back(QString::number(landmarks.vectors[16].visibility * 100.0, 'f', 2).toFloat());

    left_wrist.push_back(landmarks.vectors[15].x);
    left_wrist.push_back(landmarks.vectors[15].y);
    left_wrist.push_back(landmarks.vectors[15].z);
    left_wrist.push_back(QString::number(landmarks.vectors[15].visibility * 100.0, 'f', 2).toFloat());

    right_hip.push_back(landmarks.vectors[24].x);
    right_hip.push_back(landmarks.vectors[24].y);
    right_hip.push_back(landmarks.vectors[24].z);
    right_hip.push_back(QString::number(landmarks.vectors[24].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(right_hip);

    left_hip.push_back(landmarks.vectors[23].x);
    left_hip.push_back(landmarks.vectors[23].y);
    left_hip.push_back(landmarks.vectors[23].z);
    left_hip.push_back(QString::number(landmarks.vectors[23].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(left_hip);

    right_knee.push_back(landmarks.vectors[26].x);
    right_knee.push_back(landmarks.vectors[26].y);
    right_knee.push_back(landmarks.vectors[26].z);
    right_knee.push_back(QString::number(landmarks.vectors[26].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(right_knee);

    left_knee.push_back(landmarks.vectors[25].x);
    left_knee.push_back(landmarks.vectors[25].y);
    left_knee.push_back(landmarks.vectors[25].z);
    left_knee.push_back(QString::number(landmarks.vectors[25].visibility * 100.0, 'f', 2).toFloat());
    angle_point.append(left_knee);

    right_ankle.push_back(landmarks.vectors[28].x);
    right_ankle.push_back(landmarks.vectors[28].y);
    right_ankle.push_back(landmarks.vectors[28].z);
    right_ankle.push_back(QString::number(landmarks.vectors[28].visibility * 100.0, 'f', 2).toFloat());

    left_ankle.push_back(landmarks.vectors[27].x);
    left_ankle.push_back(landmarks.vectors[27].y);
    left_ankle.push_back(landmarks.vectors[27].z);
    left_ankle.push_back(QString::number(landmarks.vectors[27].visibility * 100.0, 'f', 2).toFloat());

    QVector<float> angle;

    float angle1 = calculateAngle(right_elbow, right_elbow, right_wrist);
    angle.append(int(angle1));
    float angle2 = calculateAngle(left_shoulder, left_elbow, left_wrist);
    angle.append(int(angle2));
    float angle3 = calculateAngle(right_elbow, right_shoulder, right_hip);
    angle.append(int(angle3));
    float angle4 = calculateAngle(left_elbow, left_shoulder, left_hip);
    angle.append(int(angle4));
    float angle5 = calculateAngle(right_shoulder, right_hip, right_knee);
    angle.append(int(angle5));
    float angle6 = calculateAngle(left_shoulder, left_hip, left_knee);
    angle.append(int(angle6));
    float angle7 = calculateAngle(right_hip, right_knee, right_ankle);
    angle.append(int(angle7));
    float angle8 = calculateAngle(left_hip, left_knee, left_ankle);
    angle.append(int(angle8));


    poseID = currentSet[currentPoseID];

    QVector<float> angle_target = allPosesAngles.value(poseID);

    score = diffCompareAngle(angle,angle_target);
    score_percentage = (1-score)*100;


    QColor fontColor;

    if(startCheck == 1)
    {
        fontColor = Qt::green;
    }
    else if( beReady == true)
    {
        fontColor = Qt::yellow;
    }
    else if(setFinish)
    {
        fontColor = Qt::green;
    }
    else if(score_percentage>70 && score_percentage<80)
    {
        fontColor = Qt::yellow ;
    }
    else if (score_percentage>80)
    {
        fontColor = Qt::green;
    }
    else if (score_percentage<70)
    {
        fontColor = Qt::red;
    }



    // Change font color
    QTextCharFormat charFormat;
    charFormat.setForeground(QBrush(fontColor));

    QTextCursor cursor = ui->textBrowser_score->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(charFormat);


    if(startCheck == 1)
    {
        return 0;
    }
    else if( beReady == true)
    {
        return 0;
    }
    else if(setFinish)
    {
        return 0;
    }


    // Set font size
    int fontSize = 20;
    QFont font = ui->textBrowser_score->font();
    font.setPointSize(fontSize);
    ui->textBrowser_score->setFont(font);  // Use setFont instead of setCurrentFont


    if (score_percentage>60){
        ui->textBrowser_score->setTextCursor(cursor);
        ui->textBrowser_score->clear();
        ui->textBrowser_score->append("\t\t\t\t      Current Score: " + QString::number(score_percentage));
    }
    else{
        ui->textBrowser_score->setTextCursor(cursor);
        ui->textBrowser_score->clear();
         ui->textBrowser_score->append("\t\t\t         Current Score is so LOW! ");
    }


    QTextCharFormat whiteFormat;

    whiteFormat.setForeground(QBrush(Qt::white));
    // cursor.movePosition(QTextCursor::End);
    // cursor.insertBlock();
    // cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.mergeCharFormat(whiteFormat);
    ui->textBrowser_score->setTextCursor(cursor);


    comparePose(angle_point,angle, angle_target);

}

float Desktop::calculateAngle(QVector<float> a, QVector<float> b, QVector<float> c)
{

    float radians = atan2(c[1] - b[1], c[0] - b[0]) - atan2(a[1] - b[1], a[0] - b[0]);
    float angle = std::abs(radians * 180.0 / M_PI);

    if (angle > 180.0) {
        angle = 360 - angle;
    }

    return angle;
}

float Desktop::diffCompareAngle(QVector<float> x, QVector<float> y){

    QVector<float> new_x;
    for(int i=0; i<x.size(); i++){
        float z = std::abs(x[i] - y[i])/((x[i]+ y[i])/2);
        new_x.push_back(z);
    }
    return Average(new_x);
}

float Desktop::Average(QVector<float> vec){
    float sum = 0;
    for(int i = 0; i < vec.size(); ++i)
    {
        sum += vec[i];
    }
    return sum / vec.size();
}
int countdown = 0;
int perfectCounter = 0;
int myCounter = 0;

void Desktop::comparePose(QVector<float> angle_point, QVector<float> angle_user, QVector<float> angle_target)
{
    int stage = 0;
//    painter.drawText(10, 30, QString("Score:"));
//    painter.drawText(10, 380, QString("Time:"));
//    painter.drawText(100, 380, QString::number(countdown));
//    painter.drawText(10, 400, QString("PerfectCount:"));
//    painter.drawText(200, 400, QString::number(perfectCounter));
//    painter.drawText(10, 420, QString("Accuracy:"));

    if (angle_user[0] < (angle_target[0] - 15))
        ui->textBrowser_score->append("Extend the right arm at elbow");

    if (angle_user[0] > (angle_target[0] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Fold the right arm at elbow");
    }

    if (angle_user[1] < (angle_target[1] - 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Extend the left arm at elbow");
    }

    if (angle_user[1] > (angle_target[1] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Fold the left arm at elbow");
    }

    if (angle_user[2] < (angle_target[2] - 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Lift your right arm");
    }

    if (angle_user[2] > (angle_target[2] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Put your arm down a little");
    }

    if (angle_user[3] < (angle_target[3] - 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Lift your left arm");
    }

    if (angle_user[3] > (angle_target[3] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Put your arm down a little");
    }

    if (angle_user[4] < (angle_target[4] - 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Extend the angle at right hip");
    }

    if (angle_user[4] > (angle_target[4] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Reduce the angle at right hip");
    }

    if (angle_user[5] < (angle_target[5] - 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Extend the angle at left hip");
    }

    if (angle_user[5] > (angle_target[5] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Reduce the angle at left hip");
    }

    if (angle_user[6] < (angle_target[6] - 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Extend the angle of right knee");
    }

    if (angle_user[6] > (angle_target[6] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Reduce the angle at right knee");
    }

    if (angle_user[7] < (angle_target[7] - 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Extend the angle at left knee");
    }

    if (angle_user[7] > (angle_target[7] + 15)) {
        stage = stage + 1;
        ui->textBrowser_score->append("Reduce the angle at left knee");
    }


    return;
}
