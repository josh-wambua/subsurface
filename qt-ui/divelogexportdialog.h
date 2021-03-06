#ifndef DIVELOGEXPORTDIALOG_H
#define DIVELOGEXPORTDIALOG_H

#include <QDialog>
#include <QTextStream>
#include "helpers.h"
#include "statistics.h"

class QAbstractButton;

namespace Ui {
	class DiveLogExportDialog;
}

void exportHTMLstatisticsTotal(QTextStream &out, stats_t *total_stats);

class DiveLogExportDialog : public QDialog {
	Q_OBJECT

public:
	explicit DiveLogExportDialog(QWidget *parent = 0);
	~DiveLogExportDialog();

private
slots:
	void on_buttonBox_accepted();
	void on_exportGroup_buttonClicked(QAbstractButton *);

private:
	Ui::DiveLogExportDialog *ui;
	void showExplanation();
	void exportHtmlInit(const QString &filename);
	void exportHTMLsettings(const QString &filename);
	void exportHTMLstatistics(const QString &filename);
	void copy_and_overwrite(const QString &fileName, const QString &newName);
};

#endif // DIVELOGEXPORTDIALOG_H
