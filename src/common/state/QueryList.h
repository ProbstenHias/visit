#ifndef QUERYLIST_H
#define QUERYLIST_H
#include <state_exports.h>
#include <string>
#include <AttributeSubject.h>

// ****************************************************************************
// Class: QueryList
//
// Purpose:
//    List of supported queries
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   Fri Jul 11 10:05:12 PDT 2003
//
// Modifications:
//   
// ****************************************************************************

class STATE_API QueryList : public AttributeSubject
{
public:
    enum QueryType
    {
        DatabaseQuery,
        PointQuery,
        LineQuery
    };
    enum CoordinateRepresentation
    {
        WorldSpace,
        ScreenSpace
    };

    QueryList();
    QueryList(const QueryList &obj);
    virtual ~QueryList();

    virtual void operator = (const QueryList &obj);
    virtual bool operator == (const QueryList &obj) const;
    virtual bool operator != (const QueryList &obj) const;

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectNames();
    void SelectTypes();
    void SelectCoordRep();

    // Property setting methods
    void SetNames(const stringVector &names_);
    void SetTypes(const intVector &types_);
    void SetCoordRep(const intVector &coordRep_);

    // Property getting methods
    const stringVector &GetNames() const;
          stringVector &GetNames();
    const intVector    &GetTypes() const;
          intVector    &GetTypes();
    const intVector    &GetCoordRep() const;
          intVector    &GetCoordRep();

    // Persistence methods
    virtual bool CreateNode(DataNode *node, bool forceAdd);
    virtual void SetFromNode(DataNode *node);

    // Enum conversion functions
    static std::string QueryType_ToString(QueryType);
    static bool QueryType_FromString(const std::string &, QueryType &);
protected:
    static std::string QueryType_ToString(int);
public:
    static std::string CoordinateRepresentation_ToString(CoordinateRepresentation);
    static bool CoordinateRepresentation_FromString(const std::string &, CoordinateRepresentation &);
protected:
    static std::string CoordinateRepresentation_ToString(int);
public:

    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void AddQuery(const std::string &name, QueryType t, CoordinateRepresentation rep = WorldSpace);
    bool QueryExists(const std::string &name, QueryType t, CoordinateRepresentation rep = WorldSpace);
private:
    stringVector names;
    intVector    types;
    intVector    coordRep;
};

#endif
