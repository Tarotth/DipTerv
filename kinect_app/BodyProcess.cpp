#include "stdafx.h"
#include <strsafe.h>
#include "resource.h"
#include "BodyProcess.h"
#include "ogrewidgetv2.h"

static const float c_JointThickness = 3.0f;
static const float c_TrackedBoneThickness = 6.0f;
static const float c_InferredBoneThickness = 1.0f;
static const float c_HandSize = 30.0f;


Ogre::SceneNode* rootNode;
Ogre::SceneNode* sphereNode[25];
Ogre::Entity* mEntity[25];



/// <summary>
/// Constructor
/// </summary>
BodyProcess::BodyProcess() :
    m_hWnd(NULL),
    m_nStartTime(0),
    m_nLastCounter(0),
    m_nFramesSinceUpdate(0),
    m_fFreq(0),
    m_nNextStatusTime(0LL),
    m_pKinectSensor(NULL),
    m_pCoordinateMapper(NULL),
    m_pBodyFrameReader(NULL),
    m_pD2DFactory(NULL),
    m_pRenderTarget(NULL),
    m_pBrushJointTracked(NULL),
    m_pBrushJointInferred(NULL),
    m_pBrushBoneTracked(NULL),
    m_pBrushBoneInferred(NULL),
    m_pBrushHandClosed(NULL),
    m_pBrushHandOpen(NULL),
    m_pBrushHandLasso(NULL)
{
    LARGE_INTEGER qpf = {0};
    if (QueryPerformanceFrequency(&qpf))
    {
        m_fFreq = double(qpf.QuadPart);
    }

	renderer = QOgreWidgetv2::getInstance();


	rootNode = renderer->getSceneManager()->getRootSceneNode();

	for (int i = 0; i < 25; i++)
	{
		Ogre::String number = Ogre::StringConverter::toString(i + 1);

		sphereNode[i] = rootNode->createChildSceneNode();
		mEntity[i] = renderer->getSceneManager()->createEntity("mySphere" + number, Ogre::SceneManager::PT_SPHERE);
		sphereNode[i]->attachObject(mEntity[i]);
		mEntity[i]->setMaterialName("Shader1_HLSL_4_0");
		sphereNode[i]->setScale(Ogre::Vector3(0.01, 0.01, 0.01));
	}

	InitializeDefaultSensor();
}
  

/// <summary>
/// Destructor
/// </summary>
BodyProcess::~BodyProcess()
{
    //DiscardDirect2DResources();

    // clean up Direct2D
    SafeRelease(m_pD2DFactory);

    // done with body frame reader
    SafeRelease(m_pBodyFrameReader);

    // done with coordinate mapper
    SafeRelease(m_pCoordinateMapper);

    // close the Kinect Sensor
    if (m_pKinectSensor)
    {
        m_pKinectSensor->Close();
    }

    SafeRelease(m_pKinectSensor);
}



/// <summary>
/// Main processing function
/// </summary>
void BodyProcess::Update()
{
    if (!m_pBodyFrameReader)
    {
        return;
    }

    IBodyFrame* pBodyFrame = NULL;

    HRESULT hr = m_pBodyFrameReader->AcquireLatestFrame(&pBodyFrame);

    if (SUCCEEDED(hr))
    {
        INT64 nTime = 0;

        hr = pBodyFrame->get_RelativeTime(&nTime);

        IBody* ppBodies[BODY_COUNT] = {0};

        if (SUCCEEDED(hr))
        {
            hr = pBodyFrame->GetAndRefreshBodyData(_countof(ppBodies), ppBodies);
        }

        if (SUCCEEDED(hr))
        {
            ProcessBody(nTime, BODY_COUNT, ppBodies);
        }

        for (int i = 0; i < _countof(ppBodies); ++i)
        {
            SafeRelease(ppBodies[i]);
        }
    }

    SafeRelease(pBodyFrame);
}

/// <summary>
/// Initializes the default Kinect sensor
/// </summary>
/// <returns>indicates success or failure</returns>
void BodyProcess::InitializeDefaultSensor()
{
    HRESULT hr;

    hr = GetDefaultKinectSensor(&m_pKinectSensor);
    if (FAILED(hr))
    {
        return;
    }

    if (m_pKinectSensor)
    {
        // Initialize the Kinect and get coordinate mapper and the body reader
        IBodyFrameSource* pBodyFrameSource = NULL;

        hr = m_pKinectSensor->Open();

        if (SUCCEEDED(hr))
        {
            hr = m_pKinectSensor->get_CoordinateMapper(&m_pCoordinateMapper);
        }

        if (SUCCEEDED(hr))
        {
            hr = m_pKinectSensor->get_BodyFrameSource(&pBodyFrameSource);
        }

        if (SUCCEEDED(hr))
        {
            hr = pBodyFrameSource->OpenReader(&m_pBodyFrameReader);
        }

        SafeRelease(pBodyFrameSource);
    }

    if (!m_pKinectSensor || FAILED(hr))
    {
        SetStatusMessage(L"No ready Kinect found!", 10000, true);
        return;
    }
}

/// <summary>
/// Handle new body data
/// <param name="nTime">timestamp of frame</param>
/// <param name="nBodyCount">body data count</param>
/// <param name="ppBodies">body data in frame</param>
/// </summary>
void BodyProcess::ProcessBody(INT64 nTime, int nBodyCount, IBody** ppBodies)
{

    //HRESULT hr = EnsureDirect2DResources();

    if (/*SUCCEEDED(hr) && m_pRenderTarget && */m_pCoordinateMapper)
    {
        //m_pRenderTarget->BeginDraw();
        //m_pRenderTarget->Clear();

        RECT rct;
        GetClientRect(GetDlgItem(m_hWnd, IDC_VIDEOVIEW), &rct);
        int width = rct.right;
        int height = rct.bottom;


        for (int i = 0; i < nBodyCount; ++i)
        {
            IBody* pBody = ppBodies[i];
            if (pBody)
            {
                BOOLEAN bTracked = false;
                HRESULT hr = pBody->get_IsTracked(&bTracked);

                if (SUCCEEDED(hr) && bTracked)
                {
                    Joint joints[JointType_Count]; 
                    D2D1_POINT_2F jointPoints[JointType_Count];
                    HandState leftHandState = HandState_Unknown;
                    HandState rightHandState = HandState_Unknown;

                    pBody->get_HandLeftState(&leftHandState);
                    pBody->get_HandRightState(&rightHandState);

                    hr = pBody->GetJoints(_countof(joints), joints);
                    if (SUCCEEDED(hr))
                    {

						
						

                        for (int j = 0; j < _countof(joints); j++)
                        {
                            //jointPoints[j] = BodyToScreen(joints[j].Position, width, height);

							sphereNode[j]->setPosition(Ogre::Vector3(joints[j].Position.X * 10, joints[j].Position.Y * 10, joints[j].Position.Z *10));
                        }



                        /*DrawBody(joints, jointPoints);

                        DrawHand(leftHandState, jointPoints[JointType_HandLeft]);
                        DrawHand(rightHandState, jointPoints[JointType_HandRight]);*/
                    }
                }
            }
        }

        //hr = m_pRenderTarget->EndDraw();

        // Device lost, need to recreate the render target
        // We'll dispose it now and retry drawing
        //if (D2DERR_RECREATE_TARGET == hr)
        //{
        //    hr = S_OK;
        //    DiscardDirect2DResources();
        //}
    }

    if (!m_nStartTime)
    {
        m_nStartTime = nTime;
    }

    double fps = 0.0;

    LARGE_INTEGER qpcNow = {0};
    if (m_fFreq)
    {
        if (QueryPerformanceCounter(&qpcNow))
        {
            if (m_nLastCounter)
            {
                m_nFramesSinceUpdate++;
                fps = m_fFreq * m_nFramesSinceUpdate / double(qpcNow.QuadPart - m_nLastCounter);
            }
        }
    }

    WCHAR szStatusMessage[64];
    StringCchPrintf(szStatusMessage, _countof(szStatusMessage), L" FPS = %0.2f    Time = %I64d", fps, (nTime - m_nStartTime));

    if (SetStatusMessage(szStatusMessage, 1000, false))
    {
        m_nLastCounter = qpcNow.QuadPart;
        m_nFramesSinceUpdate = 0;
    }
}

/// <summary>
/// Set the status bar message
/// </summary>
/// <param name="szMessage">message to display</param>
/// <param name="showTimeMsec">time in milliseconds to ignore future status messages</param>
/// <param name="bForce">force status update</param>
bool BodyProcess::SetStatusMessage(_In_z_ WCHAR* szMessage, DWORD nShowTimeMsec, bool bForce)
{
    INT64 now = GetTickCount64();

    if (m_hWnd && (bForce || (m_nNextStatusTime <= now)))
    {
        SetDlgItemText(m_hWnd, IDC_STATUS, szMessage);
        m_nNextStatusTime = now + nShowTimeMsec;

        return true;
    }

    return false;
}


///// <summary>
///// Draws a body 
///// </summary>
///// <param name="pJoints">joint data</param>
///// <param name="pJointPoints">joint positions converted to screen space</param>
//void BodyProcess::DrawBody(const Joint* pJoints, const D2D1_POINT_2F* pJointPoints)
//{
//    // Draw the bones
//
//    // Torso
//    DrawBone(pJoints, pJointPoints, JointType_Head, JointType_Neck);
//    DrawBone(pJoints, pJointPoints, JointType_Neck, JointType_SpineShoulder);
//    DrawBone(pJoints, pJointPoints, JointType_SpineShoulder, JointType_SpineMid);
//    DrawBone(pJoints, pJointPoints, JointType_SpineMid, JointType_SpineBase);
//    DrawBone(pJoints, pJointPoints, JointType_SpineShoulder, JointType_ShoulderRight);
//    DrawBone(pJoints, pJointPoints, JointType_SpineShoulder, JointType_ShoulderLeft);
//    DrawBone(pJoints, pJointPoints, JointType_SpineBase, JointType_HipRight);
//    DrawBone(pJoints, pJointPoints, JointType_SpineBase, JointType_HipLeft);
//    
//    // Right Arm    
//    DrawBone(pJoints, pJointPoints, JointType_ShoulderRight, JointType_ElbowRight);
//    DrawBone(pJoints, pJointPoints, JointType_ElbowRight, JointType_WristRight);
//    DrawBone(pJoints, pJointPoints, JointType_WristRight, JointType_HandRight);
//    DrawBone(pJoints, pJointPoints, JointType_HandRight, JointType_HandTipRight);
//    DrawBone(pJoints, pJointPoints, JointType_WristRight, JointType_ThumbRight);
//
//    // Left Arm
//    DrawBone(pJoints, pJointPoints, JointType_ShoulderLeft, JointType_ElbowLeft);
//    DrawBone(pJoints, pJointPoints, JointType_ElbowLeft, JointType_WristLeft);
//    DrawBone(pJoints, pJointPoints, JointType_WristLeft, JointType_HandLeft);
//    DrawBone(pJoints, pJointPoints, JointType_HandLeft, JointType_HandTipLeft);
//    DrawBone(pJoints, pJointPoints, JointType_WristLeft, JointType_ThumbLeft);
//
//    // Right Leg
//    DrawBone(pJoints, pJointPoints, JointType_HipRight, JointType_KneeRight);
//    DrawBone(pJoints, pJointPoints, JointType_KneeRight, JointType_AnkleRight);
//    DrawBone(pJoints, pJointPoints, JointType_AnkleRight, JointType_FootRight);
//
//    // Left Leg
//    DrawBone(pJoints, pJointPoints, JointType_HipLeft, JointType_KneeLeft);
//    DrawBone(pJoints, pJointPoints, JointType_KneeLeft, JointType_AnkleLeft);
//    DrawBone(pJoints, pJointPoints, JointType_AnkleLeft, JointType_FootLeft);
//
//    // Draw the joints
//    for (int i = 0; i < JointType_Count; ++i)
//    {
//        D2D1_ELLIPSE ellipse = D2D1::Ellipse(pJointPoints[i], c_JointThickness, c_JointThickness);
//
//        if (pJoints[i].TrackingState == TrackingState_Inferred)
//        {
//            m_pRenderTarget->FillEllipse(ellipse, m_pBrushJointInferred);
//        }
//        else if (pJoints[i].TrackingState == TrackingState_Tracked)
//        {
//            m_pRenderTarget->FillEllipse(ellipse, m_pBrushJointTracked);
//        }
//    }
//}
//
///// <summary>
///// Draws one bone of a body (joint to joint)
///// </summary>
///// <param name="pJoints">joint data</param>
///// <param name="pJointPoints">joint positions converted to screen space</param>
///// <param name="pJointPoints">joint positions converted to screen space</param>
///// <param name="joint0">one joint of the bone to draw</param>
///// <param name="joint1">other joint of the bone to draw</param>
//void BodyProcess::DrawBone(const Joint* pJoints, const D2D1_POINT_2F* pJointPoints, JointType joint0, JointType joint1)
//{
//    TrackingState joint0State = pJoints[joint0].TrackingState;
//    TrackingState joint1State = pJoints[joint1].TrackingState;
//
//    // If we can't find either of these joints, exit
//    if ((joint0State == TrackingState_NotTracked) || (joint1State == TrackingState_NotTracked))
//    {
//        return;
//    }
//
//    // Don't draw if both points are inferred
//    if ((joint0State == TrackingState_Inferred) && (joint1State == TrackingState_Inferred))
//    {
//        return;
//    }
//
//    // We assume all drawn bones are inferred unless BOTH joints are tracked
//    if ((joint0State == TrackingState_Tracked) && (joint1State == TrackingState_Tracked))
//    {
//        m_pRenderTarget->DrawLine(pJointPoints[joint0], pJointPoints[joint1], m_pBrushBoneTracked, c_TrackedBoneThickness);
//    }
//    else
//    {
//        m_pRenderTarget->DrawLine(pJointPoints[joint0], pJointPoints[joint1], m_pBrushBoneInferred, c_InferredBoneThickness);
//    }
//}
//
///// <summary>
///// Draws a hand symbol if the hand is tracked: red circle = closed, green circle = opened; blue circle = lasso
///// </summary>
///// <param name="handState">state of the hand</param>
///// <param name="handPosition">position of the hand</param>
//void BodyProcess::DrawHand(HandState handState, const D2D1_POINT_2F& handPosition)
//{
//    D2D1_ELLIPSE ellipse = D2D1::Ellipse(handPosition, c_HandSize, c_HandSize);
//
//    switch (handState)
//    {
//        case HandState_Closed:
//            m_pRenderTarget->FillEllipse(ellipse, m_pBrushHandClosed);
//            break;
//
//        case HandState_Open:
//            m_pRenderTarget->FillEllipse(ellipse, m_pBrushHandOpen);
//            break;
//
//        case HandState_Lasso:
//            m_pRenderTarget->FillEllipse(ellipse, m_pBrushHandLasso);
//            break;
//    }
//}