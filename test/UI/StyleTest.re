open Rejest;
open Revery_UI;
open Revery_Core.Colors;
open Style;

test("Style API tests", () => {
  test("that a style record is created correctly", () => {
    let styles =
      create(~userStyles=[height(1), width(2), fontFamily("Roboto")], ());
    expect(styles.height).toEqual(1);
    expect(styles.width).toEqual(2);
    expect(styles.fontFamily).toEqual("Roboto");
  });

  test("defaults should be correctly set", () => {
    let styles = create(~userStyles=[height(1), width(2)], ());
    expect(styles.position).toEqual(LayoutTypes.Relative);
    expect(styles.border).toEqual(Border.make());
  });

  test("it correctly sets a margin", () => {
    let styles =
      create(
        ~userStyles=[
          margin(1),
          marginLeft(7),
          marginTop(4),
          marginRight(8),
          marginBottom(9),
        ],
        (),
      );
    expect(styles.margin).toEqual(1);
    expect(styles.marginBottom).toEqual(9);
    expect(styles.marginTop).toEqual(4);
    expect(styles.marginRight).toEqual(8);
    expect(styles.marginBottom).toEqual(9);
  });

  test("it correctly sets a border", () => {
    let styles =
      create(
        ~userStyles=[
          border({color: black, width: 2}),
          borderLeft({color: rebeccaPurple, width: 2}),
          borderTop({color: red, width: 2}),
          borderRight({color: blue, width: 2}),
          borderBottom({color: orange, width: 2}),
          borderHorizontal({color: paleVioletRed, width: 12}),
          borderVertical({color: paleTurquoise, width: 18}),
        ],
        (),
      );
    expect(styles.border).toEqual({color: black, width: 2});
    expect(styles.borderBottom).toEqual({color: orange, width: 2});
    expect(styles.borderTop).toEqual({color: red, width: 2});
    expect(styles.borderRight).toEqual({color: blue, width: 2});
    expect(styles.borderLeft).toEqual({color: rebeccaPurple, width: 2});
    expect(styles.borderHorizontal).toEqual({
      color: paleVioletRed,
      width: 12,
    });
    expect(styles.borderVertical).toEqual({color: paleTurquoise, width: 18});
  });
});
