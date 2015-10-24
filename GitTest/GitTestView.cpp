
// GitTestView.cpp : implementation of the CGitTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GitTest.h"
#endif

#include "GitTestDoc.h"
#include "GitTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGitTestView

IMPLEMENT_DYNCREATE(CGitTestView, CView)

BEGIN_MESSAGE_MAP(CGitTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGitTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGitTestView construction/destruction

CGitTestView::CGitTestView()
{
	// TODO: add construction code here

}

CGitTestView::~CGitTestView()
{
}

BOOL CGitTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGitTestView drawing

void CGitTestView::OnDraw(CDC* /*pDC*/)
{
	CGitTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CGitTestView printing


void CGitTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGitTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGitTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGitTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGitTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGitTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGitTestView diagnostics

#ifdef _DEBUG
void CGitTestView::AssertValid() const
{
	CView::AssertValid();
}

void CGitTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGitTestDoc* CGitTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGitTestDoc)));
	return (CGitTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CGitTestView message handlers
