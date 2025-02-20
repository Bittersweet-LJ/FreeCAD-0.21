/***************************************************************************
 *   Copyright (c) 2010 Werner Mayer <wmayer[at]users.sourceforge.net>     *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#ifndef GUI_SOFCVECTORIZEU3DACTION_H
#define GUI_SOFCVECTORIZEU3DACTION_H

#include <fstream>
#include <Inventor/annex/HardCopy/SoVectorizeAction.h>
#include <Inventor/annex/HardCopy/SoVectorOutput.h>


namespace Gui {

class GuiExport SoU3DVectorOutput : public SoVectorOutput {
public:
    SoU3DVectorOutput();
    virtual ~SoU3DVectorOutput();

    virtual SbBool openFile (const char *filename);
    virtual void closeFile ();
    std::fstream& getFileStream();

private:
    std::fstream file;
};

/**
 * @author Werner Mayer
 */
class SoFCVectorizeU3DActionP;
class GuiExport SoFCVectorizeU3DAction : public SoVectorizeAction {
    using inherited = SoVectorizeAction;

    SO_ACTION_HEADER(SoFCVectorizeU3DAction);

public:
    SoFCVectorizeU3DAction();
    virtual ~SoFCVectorizeU3DAction();

    static void initClass();
    SoU3DVectorOutput * getU3DOutput() const;

protected:
    virtual void beginTraversal(SoNode * node);
    virtual void endTraversal(SoNode *node);
    virtual void printHeader() const;
    virtual void printFooter() const;
    virtual void printBackground() const;
    virtual void printItem(const SoVectorizeItem * item) const;
    virtual void printViewport() const;

private:
    static void actionMethod(SoAction *, SoNode *);

private:
    SoFCVectorizeU3DActionP* p;
    friend class SoFCVectorizeU3DActionP;
};

} // namespace Gui

#endif // GUI_SOFCVECTORIZEU3DACTION_H
