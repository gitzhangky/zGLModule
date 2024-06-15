#include "Mainwindow.h"
#include"ui_Mainwindow.h"
#include<qmenu.h>
namespace widgets
{
	Mainwindow::Mainwindow(QWidget* parent) :QMainWindow(parent)
	{
		_ui = new Ui::Mainwindow;
		_ui->setupUi(this);

		openGLWidget = new OpenGLWidget(this);
		setWindowIcon(QIcon(QString(":/new/prefix1/Resource/icons/11.ico")));
		QHBoxLayout* hLayout = new QHBoxLayout(_ui->widget);
		hLayout->addWidget(openGLWidget);
		hLayout->setMargin(0);
		this->resize(1200, 800);
		initTreeWidget();

	}

	void Mainwindow::initTreeWidget()
	{
		QTreeWidgetItem* item = new QTreeWidgetItem;
		item->setText(0, tr("triangle"));
		_ui->treeWidget->addTopLevelItem(item);
		_ui->treeWidget->setStyleSheet("QTreeView::item { height: 25px; }");
		_ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
		connect(_ui->treeWidget, &QTreeWidget::customContextMenuRequested, this, &Mainwindow::slot_contextMenu);

	}

	void Mainwindow::slot_contextMenu(const QPoint& pos)
	{
		QMenu menu;
		QAction* createTriangle = menu.addAction(tr("Create a triangle"));
		QAction* deleteTriangle = menu.addAction(tr("Delete a triangle"));

		menu.exec(pos);
	}

}
